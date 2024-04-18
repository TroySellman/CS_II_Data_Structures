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
        stack<int>  x;
        stack<int> y;

        assert(x.empty());
        assert(y.empty());

        // TEST
        x.push(2);
        y = x;

        // VERIFY
        assert(!x.empty());
        assert(!y.empty());
        assert(x.top() == 2);
        assert(y.top() == 2);

        x.push(11111111111111111111);
        assert(x.top() == 11111111111111111111);

        x.pop();
        assert(x.top() == 2);
        x.pop();
        assert(x.top() == 0);

     }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String>  x;
        stack<String> y;

        assert(x.empty());
        assert(y.empty());

        // TEST
        x.push("abcdefghijklmnopqrstuvwxyz");
        y = x;

        // VERIFY
        assert(!x.empty());
        assert(!y.empty());
        assert(x.top() == "abcdefghijklmnopqrstuvwxyz");
        assert(y.top() == "abcdefghijklmnopqrstuvwxyz");

        x.push("z");
        assert(x.top() == "z");

        x.pop();
        assert(x.top() == "abcdefghijklmnopqrstuvwxyz");
        x.pop();
        assert(x.top() == "");

     }

    
    std::cout << "Done testing Assign/Swap/Pop/Push." << std::endl;
    return 0;
}

