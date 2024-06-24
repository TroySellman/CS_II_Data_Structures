// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(100);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 300); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(256);

        // Test 
        bi = bi.timesDigit(9);
        
        // Verify
        assert(bi == 2304);
    }

    {
        //------------------------------------------------------

        // Setup fixture
        bigint bi(123456789);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 1111111101); 

    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(987654321);

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == "4938271605"); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(111111111);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 111111111); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi2("987654321098765432109876543210987654321098765432109876543210");

        // Test 
        bi2 = bi2.timesDigit(8);

        // Verify
        assert(bi2 == "7901234568790123456879012345687901234568790123456879012345680"); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi3("999999999999999999999999999999999999999999999999999999999999");

        // Test 
        bi3 = bi3.timesDigit(5);

        // Verify
        assert(bi3 == "4999999999999999999999999999999999999999999999999999999999995"); 
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi4("123456789012345678901234567890123456789012345678901234567890");

        // Test 
        bi4 = bi4.timesDigit(1);

        // Verify
        assert(bi4 == "123456789012345678901234567890123456789012345678901234567890"); 
    }

    {    
        std::cout << "Done testing bigint * digit" << std::endl;
        return 0;
    }
}