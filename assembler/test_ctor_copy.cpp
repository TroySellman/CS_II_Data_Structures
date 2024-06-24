//  Stack class test program
//
//  Tests: XXX 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;
        x.push(1);
        stack<int> copy(x);
        // VERIFY
        assert(x.top() == copy.top());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  x;
        x.push('a');
        stack<char> copy(x);
        // VERIFY
        assert(x.top() == copy.top());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;
        x.push("abcdefghijklmnopqrstuvwxyz");
        stack<String> copy(x);
        // VERIFY
        assert(x.top() == copy.top());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;
        x.push("abcdefghijklmnopqrstuvwxyz");
        x.push("abc");
        x.push("def");
        stack<String> copy(x);
        // VERIFY
        assert(x.top() == copy.top());
    }


    
    std::cout << "Done testing Copy Constructor." << std::endl;
    return 0;
}

