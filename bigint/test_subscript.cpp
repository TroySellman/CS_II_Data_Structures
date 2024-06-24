// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi == 4); 
        assert(digit == 4);
    }

    
    //Add test cases!!

    {
        // Setup
        bigint bi;

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi == 0); 
        assert(digit == 0);
    }

    {
        // Setup
        bigint bi(2345);

        //Test
        int digit1 = bi[0];
        int digit2 = bi[1];
        int digit3 = bi[2];
        int digit4 = bi[3];

        // Verify
        assert(bi == 2345); 
        assert(digit1 == 5);
        assert(digit2 == 4);
        assert(digit3 == 3);
        assert(digit4 == 2);

    }



    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

