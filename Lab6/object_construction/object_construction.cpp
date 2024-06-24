#include "object_construction.hpp"

//Defualt Constructor
Darray::Darray() : ptr(0), cap() {
    std::cout << "Called: Defualt Constructor" << "\n";
}

// Destructor
Darray::~Darray() {
    std::cout << "Called: Destructor" << "\n";
    delete[] ptr;
}

// Copy constructor
Darray::Darray(const Darray& actual) {
    std::cout << "Called: Copy Constructor" << "\n";
    cap = actual.cap;
    ptr = new int[cap];
    for (int i = 0; i < cap; ++i) {
        ptr[i] = actual.ptr[i];
    }
}

void Darray::swap(Darray& rhs) {
    //swaps ptr
    int *temp = ptr;
    ptr       = rhs.ptr;
    rhs.ptr   = temp;
    //swaps capacity
    int ctemp = cap;
    cap       = rhs.cap;
    rhs.cap   = ctemp;
}

// assignment
Darray& Darray::operator=(Darray rhs) {
    std::cout << "Called: Assignment" << "\n";
    swap(rhs);
    return *this;
}


