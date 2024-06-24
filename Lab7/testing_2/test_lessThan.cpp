#include <iostream>
#include "string.hpp"

int main (){

	    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a");
        String  right("z");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
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
    }
	
	{
		std::cout << "Done Testing Less Than\n";
	}

return 0;
}
