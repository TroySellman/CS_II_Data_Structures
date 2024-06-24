//  String class test program
// 
//  
//  Tests: Input Operator
//
 
#include "string.hpp"
#include <cassert>
#include <iostream> 
#include <fstream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        std::ifstream file("test_input.txt");
        if (!file.is_open()) {
            std::cout << "Unable to open file\n";
        }
        String  str;

        // TEST
        file >> str;
        while(!file.eof()) {
        std::cout << str << " ";
        file >> str;
        }
        std::cout << str << std::endl;
        file.close();
    }
    
    std::cout << "Done testing Input Operator." << std::endl;
    return 0;
}
