// File: main.cpp
//
// CS 23001 Project 1 bigint 
//
// Basics for openning a file for milestone 2

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    while(!in.eof()) {//Until end of file
        //Read two bigints
        bigint b1;
        bigint b2;
        in >> b1;
        in >> b2;
        //Print them out
        if (in.eof()) break;
        std::cout << "First  Bigint: " << b1 << "\n";
        std::cout << "Second Bigint: " << b2 << "\n";
        //Add them together
        bigint sum;
        sum = b1 + b2;
        //Print out results
        std::cout << "Sum: " << sum << "\n";
    }
    in.close();
    return 0;
}
