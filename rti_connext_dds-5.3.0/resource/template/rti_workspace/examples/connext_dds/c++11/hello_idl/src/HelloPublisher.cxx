/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <dds/dds.hpp>
#include "HelloPublisher.hpp"
#include "HelloWorld.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

class HelloPublisher::HelloPublisherImpl {
public:
    HelloPublisherImpl(int domain_id, const std::string& topic_name, bool verbose) :
        verbose(verbose),
        participant(domain_id),
        topic(participant, topic_name),
        writer(Publisher(participant), topic)
    {
    }

    void publish(int data_size, int sample_count)
    {
        // Before starting publishing, wait for readers
        std::cout << "Waiting to match readers..." << std::endl;
        while (writer.publication_matched_status().current_count() < 1) {
            rti::util::sleep(Duration::from_millisecs(500));
        }
        std::cout << "Found reader" << std::endl;

        // Create an instance
        HelloWorld instance;
        instance.prefix() = "Hello world";
        instance.payload().resize(data_size);
        for (int i = 0; i < data_size; i++) {
            instance.payload()[i] = i & 0xFF;
        }

        // Write samples from the instance
        std::cout << "Sending data..." << std::endl;
        int consecutive_errors = 0;
        for (int i = 0; sample_count == 0 || i < sample_count; i++) {
            instance.sampleId(i + 1);

            try {
                writer.write(instance);
                consecutive_errors = 0;
            } catch (const TimeoutError&) {
                consecutive_errors++;
                if (consecutive_errors == MaxConsecutiveWriteErrors) {
                    std::cerr << "! Reached maximum number of failure, "
                              << "stopping writer..." << std::endl;
                    break;
                }
            }

            if (verbose && (i + 1) % 1000 == 0) {
                std::cout << "Sent " << i + 1 << " samples" << std::endl;
            }
        }

        writer.wait_for_acknowledgments(Duration::from_secs(10));
        std::cout << "Sent " << instance.sampleId() << " samples"
                  << std::endl;
    }

private:
    static const int MaxConsecutiveWriteErrors = 10;
    bool verbose;
    DomainParticipant participant;
    Topic<HelloWorld> topic;
    DataWriter<HelloWorld> writer;
};

HelloPublisher::HelloPublisher(int domain_id, const std::string& topic_name, bool verbose)
    : impl(new HelloPublisherImpl(domain_id, topic_name, verbose))
{
}

HelloPublisher::~HelloPublisher()
{
    delete impl;
}

void HelloPublisher::publish(int data_size, int sample_count)
{
    impl->publish(data_size, sample_count);
}
