//  String class test program
// 
// 
//  Tests: Addition Operator
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
        String  left;
        String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("c");
        String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "c");
        assert(left   == "c");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Hello ");
        String  right("World");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "Hello World");
        assert(left   == "Hello ");
        assert(right  == "World");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a b c d ");
        String  right("e f g h i");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "a b c d e f g h i");
        assert(left   == "a b c d ");
        assert(right  == "e f g h i");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyz");
        String  right("abcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(left   == "abcdefghijklmnopqrstuvwxyz");
        assert(right  == "abcdefghijklmnopqrstuvwxyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        String  right("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(left   == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(right  == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
    }


    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        String  right("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(left   == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(right  == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        String  right("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(left   == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(right  == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
    }
    
    std::cout << "Done testing Addition Operator." << std::endl;
    return 0;
}
