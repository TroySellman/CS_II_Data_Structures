/*
Create a main body (name the file multiply.cpp) that reads from the file data1-2.txt and does the following:
Test for success of opening the file in your program.
Read in two big numbers (i.e., input bigint) and write both out separated by a blank line.
Multiply the two together and write the result.
Then read in two more big numbers, writing them out, multiplying them, and writing the result until end of file.
All output must be labeled and neat.
The command make multiply will build and run this program.
*/

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-2.txt");      // Open a file
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
        std::cout << "First Bigint: " << b1 << "\n";
        std::cout << "\n";
        std::cout << "Second Bigint: " << b2 << "\n";
        std::cout << "\n";
        //Add them together
        bigint prod;
        prod = b1 * b2;
        //Print out results
        std::cout << "Product: " << prod << "\n";
        std::cout << "\n";
    }
    in.close();
    return 0;
}
