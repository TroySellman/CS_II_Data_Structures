#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int CAPACITY = 200; // number of digits in the number

class bigint {
public:
    bigint();
    bigint(int);
    bigint(const char[]); // ['3', '0', '4', '\0']  \0 ends the iteration
    void debugPrint(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, const bigint&);
    bool operator==(const bigint&) const;

private:
    int numArray[CAPACITY];
};

#endif
