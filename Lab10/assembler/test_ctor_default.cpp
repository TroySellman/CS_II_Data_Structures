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
        stack<int> test;
        assert(test.empty() == true); 
    }  
    
    
    {
        stack<int> test;
        assert(test.full() == false); 
    }
   


    {
        stack<String> test;
        assert(test.empty() == true); 
    }  
    
    
    {
        stack<String> test;
        assert(test.full() == false); 
    }



    {
        stack<char> test;
        assert(test.empty() == true); 
    }  
    
    
    {
        stack<char> test;
        assert(test.full() == false); 
    }


    
    {
        stack<String> test;
        assert(test.full() == false); 
    }

    
    std::cout << "Done testing Defualt Constructor." << std::endl;
    return 0;
}

