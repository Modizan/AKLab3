#include <iostream>
#include <getopt.h>

#define no_argument 0
#define require_argument 1

// args: help(h), description(d), version(v), number(n)

int main (int argc, char *argv[]) {

    bool help_flag = false;
    bool desc_flag = false;
    bool version_flag = false;
    bool unknown_flag = false;
    bool number_flag = false;

    int index;
    int arg;

    char* number_value;

    const struct option longopts[] =
    {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"description", no_argument, 0, 'd'},
        {"number", require_argument, 0, 'n'},
        {0, 0, 0, 0}
    };

    while ((arg = getopt_long(argc, argv, "hdvn:", longopts, &index)) != -1) {
        if(arg == 'h')
            help_flag = true;

        if(arg == 'd')
            desc_flag = true;

        if(arg == 'v')
            version_flag = true;

        if(arg == '?')
            unknown_flag = true;

        if(arg == 'n')
            number_flag = true;
            number_value = optarg;
    }

    if(unknown_flag == true)
        std::cout << "\nThere is unknown arguments\n";

    if(help_flag == true)
        std::cout << "\nHelp:   --help(-h) for args list\n\t--description(-d) for description\n\t--version(-v) for version\n\t--number(-n) enter the number\n";

    if(desc_flag == true)
        std::cout << "\nDescription: Laboratory work No.3\n";

    if(version_flag == true)
        std::cout << "\nVersion: 0.4\n";

    if(number_flag == true)
        std::cout << "\nNumber value: " << number_value << "\n";

    return 0;
};
