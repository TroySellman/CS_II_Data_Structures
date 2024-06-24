//  String class test program
// 
//  Tests: Equal Operator
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
        String  left("Hello");
        String  right("World");

        // TEST
        assert(!(left == right));
       
        // VERIFY
        assert(left   == "Hello");
        assert(right  == "World");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Hello");
        String  right("Hello");

        // TEST
        assert(left == right);

        // VERIFY
        assert(left   == "Hello");
        assert(right  == "Hello");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Testing if two really large strings are still equal even though there are a lot of characters in this string");
        String  right("Testing if two really large strings are still equal even though there are a lot of characters in this string");

        // TEST
        assert(left == right);

        // VERIFY
        assert(left   == "Testing if two really large strings are still equal even though there are a lot of characters in this string");
        assert(right  == "Testing if two really large strings are still equal even though there are a lot of characters in this string");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("Not An Empty String");

        // TEST
        assert(!(left == right));

        // VERIFY
        assert(left  == "");
        assert(right  == "Not An Empty String");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        String  right("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");

        // TEST
        assert(left == right);

        // VERIFY
        assert(left   == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(right  == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        String  right("abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");

        // TEST
        assert(left == right);

        // VERIFY
        assert(left   == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
        assert(right  == "abcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyzabcdefghijklmnopqrstuvwqyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;

        // TEST
        assert(left == right);

        // VERIFY
        assert(left   == "");
        assert(right  == "");
    }

    std::cout << "Done testing Equal Operator." << std::endl;
    return 0;
}
