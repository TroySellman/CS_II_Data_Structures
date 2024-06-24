//  String class test program
// 
//  
//  Tests: Less Than Operator
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
        String  left("a");
        String  right("z");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == 'a');
        assert(right  == 'z');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("z");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "abcd");
        assert(right  == "z");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("z");
        String  right("abcd");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "z");
        assert(right  == "abcd");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("dz");
        String  right("zz");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "dz");
        assert(right  == "zz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        String  right("abcdefghijklmnopqrstuvwxyz");

        // TEST
        bool result = (right < left);

        // VERIFY
        assert(result == true);
        assert(left   == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(right  == "abcdefghijklmnopqrstuvwxyz");
    }

    
    std::cout << "Done testing Less Than Operator." << std::endl;
    return 0;
}
