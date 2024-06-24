//  String class test program
// 
//  Tests: Find Character Function
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
        String  str("abcdefg");

        // TEST
        int result = str.findch(0,'a');

        // VERIFY
        assert(str    == "abcdefg");
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefg");

        // TEST
        int result = str.findch(0,'e');

        // VERIFY
        assert(str    == "abcdefg");
        assert(result == 4);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefg");

        // TEST
        int result = str.findch(0,'g');

        // VERIFY
        assert(str    == "abcdefg");
        assert(result == 6);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");

        // TEST
        int result = str.findch(0,'g');

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(result == 6);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");

        // TEST
        int result = str.findch(190,'z');

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(result == 207);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");

        // TEST
        int result = str.findch(190,'a');

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(result == -1);
    }

    
    std::cout << "Done testing Find Character Function." << std::endl;
    return 0;
}

