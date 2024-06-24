//  String class test program
//
//  Tests: Copy Constructor
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
        String  str1;
        String str2 = str1;
        // VERIFY
        assert(str2 == "");
        assert(str1 == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abc");
        String str2 = str1;
        // VERIFY
        assert(str2 == "abc");
        assert(str1 == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abcdefghijklmnopqrstuvwqyz");
        String str2 = str1;
        // VERIFY
        assert(str2 == "abcdefghijklmnopqrstuvwqyz");
        assert(str1 == "abcdefghijklmnopqrstuvwqyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        String str2 = str1;
        // VERIFY
        assert(str2 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(str1 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        String str2 = str1;
        // VERIFY
        assert(str2 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(str1 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        String str2 = str1;
        // VERIFY
        assert(str2 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(str1 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        String str2 = str1;
        // VERIFY
        assert(str2 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(str1 == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
    }

    
    
    std::cout << "Done testing Copy Consrtructor." << std::endl;
    return 0;
}

