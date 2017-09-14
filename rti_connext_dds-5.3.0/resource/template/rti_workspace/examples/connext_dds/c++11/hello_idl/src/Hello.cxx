/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <rti/config/Version.hpp>
#include <dds/dds.hpp>
#include "HelloPublisher.hpp"
#include "HelloSubscriber.hpp"
#include "HelloWorld.hpp"

struct CommandLineArguments {
    static const int DOMAIN_ID_MAX = 250;

    int domain_id;
    bool is_pub;
    int data_size;
    int sample_count;
    bool verbose;
    std::string topic_name;

    CommandLineArguments()
    {
        is_pub = false;
        domain_id = 0;
        data_size = 1024;
        sample_count = 0;
        verbose = false;
        topic_name = "Hello IDL";
    }
};

static void start_application(const CommandLineArguments &options)
{
    std::cout <<
        "# The output below depends on the QoS profile"        << std::endl <<
        "# provided to this application."                      << std::endl <<
        "# -> For more information on the provided example"    << std::endl <<
        "#    profiles, please see the Getting Started Guide." << std::endl <<
        "# -> For detailed product performance metrics, visit" << std::endl <<
        "#    http://www.rti.com/products/data_distribution/index.html" << std::endl <<
        "#    and click on Benchmarks."           << std::endl << std::endl;

    if (options.is_pub) {
        try {
            HelloPublisher publisher(
                    options.domain_id,
                    options.topic_name,
                    options.verbose);
            publisher.publish(options.data_size, options.sample_count);
        } catch (const std::exception& ex) {
            std::cerr << "Error creating publisher: " << ex.what() << std::endl;
        }
    } else {
        try {
            HelloSubscriber subscriber(
                    options.domain_id,
                    options.topic_name,
                    options.verbose,
                    options.sample_count);
            subscriber.receive();
        } catch (const std::exception& ex) {
            std::cerr << "Error creating subscriber: " << ex.what() << std::endl;
        }
    }
}

static void usage()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "    " << "Hello"
                        << " pub [arguments]     Run as publisher" << std::endl;
    std::cout << "    " << "Hello"
                        << " sub [arguments]     Run as subscriber" << std::endl;
    std::cout << "Where arguments are:" << std::endl;
    std::cout << "  -h | --help                 "
              << "Shows this page" << std::endl;
    std::cout << "  -v | --verbose              "
              << "Increase output verbosity (can be repeated)" << std::endl;
    std::cout << "  -d | --domain <domainID>    "
              << "Sets the DDS domain ID [default=0]" << std::endl;
    std::cout << "  -t | --topic <name>         "
              << "Sets topic name [default=Hello IDL]" << std::endl;
    std::cout << "  -s | --size <num>           "
              << "Sets payload size in bytes [default=1024]" << std::endl;
    std::cout << "  -c | --sampleCount <num>    "
              << "Sets number of samples to send/receive [default=0(UNLIMITED)"
              << ']' << std::endl;
    std::cout << std::endl;
}

bool get_next_argument(int argc, const char **argv, int *idx, std::string& argument)
{
    if (*idx + 1 >= argc) {
        std::cerr << "! Error: missing value for argument" << std::endl;
        usage();
        return false;
    }

    argument = std::string(argv[*idx + 1]);
    (*idx)++;

    return true;
}

bool get_next_argument(int argc, const char **argv, int *idx, int *num, int min, int max)
{
    std::string next_arg;
    if (!get_next_argument(argc, argv, idx, next_arg)) {
        return false;
    }

    char *ptr = NULL;
    *num = strtol(next_arg.c_str(), &ptr, 10);
    if (*ptr != '\0') {
        usage();
        std::cerr << "! Argument is not a number: " << next_arg << std::endl;
        return false;
    }

    if (*num < min || *num > max) {
        usage();
        std::cerr << "! Invalid argument: Number is in interval ["
                  << min << ", " << max << "]" << std::endl;
        return false;
    }

    return true;
}

bool read_arguments(int argc, const char **argv, CommandLineArguments& options)
{
    bool stop = false;

    // Ensure there are enough arguments in the command line
    if (argc < 2) {
        usage();
        std::cerr << "! Invalid number of arguments." << std::endl;
        std::cerr << "! You must specify at least running mode (pub/sub)"
                  << std::endl;
        return false;
    }

    std::string first_arg = std::string(argv[1]);
    if (first_arg == "pub") {
        options.is_pub = true;
    } else if (first_arg == "sub") {
        options.is_pub = false;
    } else if (first_arg == "-h" || first_arg == "--help") {
        usage();
        stop = true;
    } else {
        usage();
        std::cerr << "! Invalid mode: '" << first_arg << "'" << std::endl;
        std::cerr << "! Valid modes are only 'pub' or 'sub'" << std::endl;
        stop = true;
    }

    // Parse the optional arguments
    for (int i = 2; i < argc && !stop; i++) {
        std::string current_arg = std::string(argv[i]);
        if (current_arg == "-h" || current_arg == "--help") {
            usage();
            stop = true;
        } else if (current_arg == "-v" || current_arg == "--verbose") {
            options.verbose = true;
        } else if (current_arg == "-d" || current_arg == "--domain") {
            int min = 0;
            int max = CommandLineArguments::DOMAIN_ID_MAX;
            if (!get_next_argument(argc, argv, &i, &options.domain_id, min, max)) {
                stop = true;
            }
        } else if (current_arg == "-s" || current_arg == "--size") {
            int min = 1;
            int max = HELLODDS_MAX_PAYLOAD_SIZE - 1;
            if (!get_next_argument(argc, argv, &i, &options.data_size, min, max)) {
                stop = true;
            }
        } else if (current_arg == "-t" || current_arg == "--topic") {
            if (!get_next_argument(argc, argv, &i, options.topic_name)) {
                stop = true;
            }
        } else if (current_arg == "-c" || current_arg == "--sampleCount") {
            int min = 0;
            int max = INT_MAX;
            if (!get_next_argument(argc, argv, &i, &options.sample_count, min, max)) {
                stop = true;
            }
        } else {
            usage();
            std::cerr << "! Unknown argument " << current_arg << std::endl;
            stop = true;
        }
    }

    return !stop;
}

int main(int argc, const char **argv)
{
    std::cout << "Hello Example Application" << std::endl
              << "Copyright 2017 Real-Time Innovations, Inc." << std::endl
              << std::endl;

    CommandLineArguments options;
    if (!read_arguments(argc, argv, options)) {
        return 1;
    }

    if (options.verbose) {
        std::cout << "Running with the following arguments:" << std::endl;
        std::cout << "    Payload size..... : " << options.data_size << std::endl;
        std::cout << "    Sample count..... : " << options.sample_count << std::endl;
        std::cout << "    Domain ID........ : " << options.domain_id << std::endl;
        std::cout << "    Topic name....... : " << options.topic_name << std::endl;
        std::cout << "RTI Product Version.. : "
                  << rti::config::product_version().to_string() << std::endl;
    }

    start_application(options);
    dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}
