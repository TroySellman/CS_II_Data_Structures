// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

      //You need to add more test cases here. Remove this assert.
      //Add test cases as needed.
      //More Tests
    {
      
      bigint left(1);
      bigint right(3);
      bigint result;

      result = left + right;
      
      assert(left  == 1);
      assert(right == 3);
      assert(result == 4);

    }
    {

      bigint left(7);
      bigint right(8);
      bigint result;

      result = left + right;
      
      assert(left  == 7);
      assert(right == 8);
      assert(result == 15);

    }
    {
      bigint left("99999999999");
      bigint right("1");
      bigint result;

      result = left + right;
      
      assert(left  == "99999999999");
      assert(right == "1");
      assert(result == "1000000000000");

    }
    {

      bigint left(10000);
      bigint right(33333);
      bigint result;

      result = left + right;
      
      assert(left  == 10000);
      assert(right == 33333);
      assert(result == 43333);

    }
    {

      bigint left(2578);
      bigint right(3593);
      bigint result;

      result = left + right;
      
      assert(left  == 2578);
      assert(right == 3593);
      assert(result == 6171);

    }
    {

      bigint left(101);
      bigint right(0);
      bigint result;

      result = left + right;
      
      assert(left  == 101);
      assert(right == 0);
      assert(result == 101);

    }
    {

      bigint left(0);
      bigint right(101);
      bigint result;

      result = left + right;
      
      assert(left  == 0);
      assert(right == 101);
      assert(result == 101);

    }
    {

      bigint left(0);
      bigint right(0);
      bigint result;

      result = left + right;
      
      assert(left  == 0);
      assert(right == 0);
      assert(result == 0);

    }
    {

      bigint left("123456789123456789123456789123456789");
      bigint right("123456789123456789123456789123456789");
      bigint result;

      result = left + right;
      
      assert(left  == "123456789123456789123456789123456789");
      assert(right == "123456789123456789123456789123456789");
      assert(result == "246913578246913578246913578246913578");

    }
    {

      bigint left("123456789123456789123456789123456789123456789123456789123456789123456789");
      bigint right("123456789123456789123456789123456789123456789123456789123456789123456789");
      bigint result;

      result = left + right;
      
      assert(left  == "123456789123456789123456789123456789123456789123456789123456789123456789");
      assert(right == "123456789123456789123456789123456789123456789123456789123456789123456789");
      assert(result == "246913578246913578246913578246913578246913578246913578246913578246913578");

    }  
    {
    std::cout << "Done with testing addition." << std::endl;
    return 0;
    }
}
