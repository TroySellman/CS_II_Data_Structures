//  String class test program
//
//  Tests: Defualt Constructor
// 
  
#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert(str == "");

    }

    
    std::cout << "Done testing Defualt Constructor." << std::endl;
    return 0;
}

