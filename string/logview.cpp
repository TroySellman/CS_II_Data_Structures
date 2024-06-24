// File:        main.cpp   
//       
// Version:     1.1
// Date:        3/12/24
// Author:      Troy Sellman
//
// Description: Main body for logview application
// Do not change anything here
 
#include "string.hpp"
#include "logentry.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int main(int argc, char *argv[]) {
    // Options
    std::vector<String> option(4);
    option[0] = "all";
    option[1] = "bytes";
    option[2] = "host";
    option[3] = "ip";

    if (argc != 3) {      // Error if there are not 3 things on the command line
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " [ "
        << option[0] << " | "
        << option[1] << " | "
        << option[2] << " | "
        << option[3] << " ] log_file"   << std::endl;
        exit(1);         // Exit with error
    }

    std::ifstream in(argv[2]);     // Open file, quit if open fails
    if (!in) {
        std::cerr << "Error: Can not open " << argv[2] << std::endl;
        exit(2);
    }

    std::vector<LogEntry> log_entries = parse(in);   // Process the log file
    in.close();

    if (argv[1] == option[0]) {                // Handle the specified option
        output_all(std::cout, log_entries);
    }
    else if (argv[1] == option[1]) {
        std::cout << "Total number of bytes sent: " 
                  << byte_count(log_entries) << std::endl;
    }
    else if (argv[1] == option[2]) {
        by_host(std::cout, log_entries);
    }
    else if (argv[1] == option[3]) { // BONUS IMPLEMENTED HERE
        std::map<String, int> myMap;
        for (size_t i = 0; i < log_entries.size(); ++i) {
            String temp = String(log_entries[i].gethost());
            myMap[temp]++;
        }
        // iterator pointing to the first element in themap
        std::map<String, int>::iterator it = myMap.begin();
        // iterate through the map and print the elements
        while (it != myMap.end()) {
        std::cout << "Host: " << it->first
             << ", Value: " << it->second << std::endl;
            ++it;
    }

    }
    else { //Error, bad option
        std::cerr << "Unrecognized option: " << argv[1] << std::endl;
        std::cerr << "Recognized options: " 
             << option[0] << " "
             << option[1] << " "
             << option[2] << " "
             << option[3] << std::endl;
        exit(3);
    }
    return 0;
}
