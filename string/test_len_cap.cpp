 //  String class test program
//
//  Tests: Length and Capacity
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
        String  str("Hello");

        // TEST
        int length = str.length();

        // VERIFY
        assert(length == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
        int length = str.length();

        // VERIFY
        assert(length == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Hello World");

        // TEST
        int length = str.length();

        // VERIFY
        assert(length == 11);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // TEST
        int length = str.length();

        // VERIFY
        assert(length == 208);
    }




    std::cout << "Done testing length() and capacity()." << std::endl;
    return 0;
}

