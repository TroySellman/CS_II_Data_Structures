#ifndef OBJ_CONSTRUCTION_HPP
#define OBJ_CONSTRUCTION_HPP
#include <iostream>
#include <cassert>

class Darray {
public:
         Darray           ();              // defualt constructor
         Darray           (const Darray&); // copy constructor
         ~Darray          ();              // destructor
         Darray& operator=(Darray);        // assignment
    void swap             (Darray&);
private:
    int *ptr;
    int cap;
};

#endif
