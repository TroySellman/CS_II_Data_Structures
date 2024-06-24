//  String class test program
// 
//  Tests: Find String Function
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
        String  str;

        // TEST
        int result = str.findstr(0,'a');

        // VERIFY
        assert(str    == "");
        assert(result == -1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefg");

        // TEST
        int result = str.findstr(0,"abc");

        // VERIFY
        assert(str    == "abcdefg");
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefg");

        // TEST
        int result = str.findstr(1,"abc");

        // VERIFY
        assert(str    == "abcdefg");
        assert(result == -1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefg");

        // TEST
        int result = str.findstr(0,"defg");

        // VERIFY
        assert(str    == "abcdefg");
        assert(result == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // TEST
        int result = str.findstr(0,"abcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(result == 0);
    }

        {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // TEST
        int result = str.findstr(150,"abcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(result == 156);
    }


    std::cout << "Done testing Find String Function." << std::endl;
    return 0;
}

