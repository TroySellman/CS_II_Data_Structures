#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int CAPACITY = 200; // number of digits in the number

class bigint {
public:

    bigint();
    bigint(int);
    bigint(const char[]); 

    friend std::ostream& operator<<(std::ostream&, const bigint&);
    friend std::istream& operator>>(std::istream&, bigint&);

    void debugPrint(std::ostream&) const;
    bool operator==(const bigint&) const;
    bigint operator+(const bigint&) const;
    int operator[](int index) const;
    bigint operator*(const bigint&) const;
    bigint timesDigit(int) const;
    bigint times10(int) const;

private:
    int numArray[CAPACITY];
    
};

#endif
