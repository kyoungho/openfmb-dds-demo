/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <dds/dds.hpp>
#include "HelloSubscriber.hpp"
#include "HelloWorld.hpp"

using namespace dds::core;
using namespace dds::core::status;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::sub;

class HelloSubscriber::HelloSubscriberImpl
    : public DataReaderListener<HelloWorld> {
public:
    HelloSubscriberImpl(
            int domain_id,
            const std::string& topic_name,
            bool verbose,
            int sample_count) :
        verbose(verbose),
        participant(domain_id),
        topic(participant, topic_name),
        reader(Subscriber(participant), topic),
        max_samples(sample_count),
        payload_size(0),
        first_sample_id(-1),
        last_sample_id(0),
        received_samples(0),
        lost_samples(0)
    {
        reader.listener(this, StatusMask::all());
    }

    ~HelloSubscriberImpl()
    {
        reader.listener(NULL, StatusMask::none());
    }

    void on_requested_deadline_missed(
            DataReader<HelloWorld>&,
            const RequestedDeadlineMissedStatus&)
    {
        if (verbose) {
            std::cout << "->Callback: requested deadline missed." << std::endl;
        }
    }

    void on_requested_incompatible_qos(
            DataReader<HelloWorld>&,
            const RequestedIncompatibleQosStatus&)
    {
        if (verbose) {
            std::cout << "->Callback: requested incompatible QoS." << std::endl;
        }
    }

    void on_sample_rejected(
            DataReader<HelloWorld>&,
            const SampleRejectedStatus&)
    {
        if (verbose) {
            std::cout << "->Callback: sample rejected." << std::endl;
        }
    }

    void on_liveliness_changed(
            DataReader<HelloWorld>&,
            const LivelinessChangedStatus&)
    {
        if (verbose) {
            std::cout << "->Callback: liveliness changed." << std::endl;
        }
    }

    void on_sample_lost(
            DataReader<HelloWorld>&,
            const SampleLostStatus&)
    {
        lost_samples++;
        if (verbose) {
            std::cout << "->Callback: sample lost." << std::endl;
        }
    }

    void on_subscription_matched(
            DataReader<HelloWorld>&,
            const SubscriptionMatchedStatus&)
    {
        if (verbose) {
            std::cout << "->Callback: subscription matched" << std::endl;
        }
    }

    void on_data_available(DataReader<HelloWorld>& reader)
    {
        if (max_samples != 0 && received_samples >= max_samples) {
            return;
        }

        if (verbose) {
            std::cout << "->Callback: data available matched." << std::endl;
        }

        LoanedSamples<HelloWorld> samples = reader.take();
        for (LoanedSamples<HelloWorld>::iterator it = samples.begin();
                it != samples.end();
                it++) {
            if (it->info().valid()) {
                received_samples++;
                last_sample_id = it->data().sampleId();
                if (payload_size == 0) {
                    payload_size = static_cast<int>(it->data().payload().size());
                }
                if (first_sample_id == -1) {
                    first_sample_id = it->data().sampleId();
                }
            }
        }
    }

    void receive()
    {
        std::cout << std::endl
                  << "Sec.from|Total     |Total Lost|Curr Lost |Average   |"
                  << "Current   |Current" << std::endl
                  << "start   |samples   |samples   |samples   |smpls/sec |"
                  << "smpls/sec |Mb/sec" << std::endl
                  << "--------+----------+----------+----------+----------+"
                  << "----------+----------" << std::endl;

        int current_sample_id = 0;
        int current_samples_lost = 0;
        int prev_sample_id = 0;
        int prev_samples_lost = 0;
        int start_first_sequence_id = -1;
        time_t start_time = time(NULL);
        while (max_samples == 0 || received_samples < max_samples) {
            rti::util::sleep(Duration::from_secs(PollSeconds));

            if (last_sample_id < current_sample_id) {
                std::cout << "Detected multiple publishers, or the publisher "
                          << "was restarted." << std::endl
                          << "If you have multiple publishers on the network "
                          << "or you restart" << std::endl
                          << "the publisher, the statistics produced won't be "
                          << "accurate." << std::endl;
                break;
            }

            current_sample_id = last_sample_id;
            current_samples_lost = lost_samples;
            time_t now = time(NULL);

            if (current_sample_id == 0) {
                if (verbose) {
                    std::cout << "No data..." << std::endl;
                }

                continue;
            }

            if (start_first_sequence_id == -1) {
                start_first_sequence_id = first_sample_id;
                start_time = now;

                // Skip this iteration since we need at least two period to get stats
                prev_sample_id = current_sample_id;
                prev_samples_lost = current_samples_lost;
                continue;
            }

            long stat_delta_time_sec = (long)(now - start_time);
            long stat_total_samples =
                    (current_sample_id - start_first_sequence_id + 1)
                    - current_samples_lost;
            float stat_total_sample_per_sec =
                    (float) stat_total_samples / stat_delta_time_sec;
            float stat_current_samples_per_sec =
                    (float) (current_sample_id - prev_sample_id) / PollSeconds;
            long stat_sample_lost = current_samples_lost - prev_samples_lost;
            float stat_throughput = payload_size * stat_current_samples_per_sec
                    * 8.0f / (1024 * 1024);

            std::cout.setf(std::ios_base::fixed);
            std::cout.setf(std::ios_base::showpoint);
            std::cout << std::setfill(' ') << std::setw(8) << std::right
                      << stat_delta_time_sec << ' ';
            std::cout << std::setfill(' ') << std::setw(10) << std::right
                      << stat_total_samples << ' ';
            std::cout << std::setfill(' ') << std::setw(10) << std::right
                      << current_samples_lost << ' ';
            std::cout << std::setfill(' ') << std::setw(10) << std::right
                      << stat_sample_lost << ' ';
            std::cout << std::setfill(' ') << std::setw(10)
                      << std::setprecision(2) << std::right
                      << stat_total_sample_per_sec << ' ';
            std::cout << std::setfill(' ') << std::setw(10)
                      << std::setprecision(2) << std::right
                      << stat_current_samples_per_sec << ' ';
            std::cout << std::setfill(' ') << std::setw(10)
                      << std::setprecision(2) << std::right
                      << stat_throughput << ' ' << std::endl;

            prev_sample_id = current_sample_id;
            prev_samples_lost = current_samples_lost;
        }
    }

private:
    static const int PollSeconds = 1;

    bool verbose;
    DomainParticipant participant;
    Topic<HelloWorld> topic;
    DataReader<HelloWorld> reader;

    int max_samples;
    int payload_size;
    int first_sample_id;
    int last_sample_id;
    int received_samples;
    int lost_samples;
};


HelloSubscriber::HelloSubscriber(
        int domain_id,
        const std::string& topic_name,
        bool verbose,
        int sample_count)
    : impl(new HelloSubscriberImpl(domain_id, topic_name, verbose, sample_count))
{
}

HelloSubscriber::~HelloSubscriber()
{
    delete impl;
}

void HelloSubscriber::receive()
{
    impl->receive();
}
