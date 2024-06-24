#include "bigint.hpp"

//Declaration of default constructors
//default constructor that sets bigint to 0 when not provided a value.
bigint::bigint(){
    for (int i = 0; i < CAPACITY; ++i){
        numArray[i] = 0;
    }
}  

//defualt constructor that sets bigint to provided integer
bigint::bigint(int number){
    for (int i = CAPACITY-1; i >= 0; --i){
        int digit = number % 10;
        number = number / 10;
        numArray[i] = digit;
    }
}

//default constructor that sets bigint when provided characters
bigint::bigint(const char charArray[]){
    int length = 0;
    while (charArray[length]!='\0'){
        numArray[length] = charArray[length] - '0';
        ++length;
    }
}

void bigint::debugPrint(std::ostream& out) const{
    for(int i = CAPACITY-1; i>=0; --i){
        out << numArray[i] << "|";
    }
}

std::ostream& operator<<(std::ostream& out, const bigint& rhs){
    int controlVariable = 0;
    for (int i = 0; i < CAPACITY; ++i){
        if (rhs.numArray[i] != 0) ++controlVariable;
        if (controlVariable != 0) {
        out << rhs.numArray[i];
        }
    }
    if (controlVariable == 0) out << rhs.numArray[CAPACITY - 1];
    return out;
}

bool bigint::operator==(const bigint& rhs) const {
    for (int i = 0; i < CAPACITY; ++i){
        if(this->numArray[i]!=rhs.numArray[i])
            return false;
    }
    return true;
}
