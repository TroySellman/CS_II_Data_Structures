//  String class test program
//
//  Tests: Character Constructor
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
        String  str("A");

        // VERIFY
        assert(str == "A");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(' ');

        // VERIFY
        assert(str == ' ');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('\0');

        // VERIFY
        assert(str == '\0');
    }
    
    std::cout << "Done testing Character Constructor." << std::endl;
    return 0;
}

