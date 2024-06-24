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
    for (int i = CAPACITY - 1; i >= 0; --i){
        int digit = number % 10;
        number = number / 10;
        numArray[i] = digit;
    }
}

//default constructor that sets bigint when provided characters
bigint::bigint(const char charArray[]) : bigint{} {
    int length = 0;
    while (charArray[length]!='\0') ++length; // gives length of charArray
    for (int i = CAPACITY - 1; i >= CAPACITY - length; --i) {  // fills numArray with charArray's values as integers
        numArray[i] = charArray[length + i - CAPACITY] - '0';
    }
}

void bigint::debugPrint(std::ostream& out) const{
    for(int i = CAPACITY - 1; i >= 0; --i){
        out << numArray[i] << "|";
    }
}

std::ostream& operator<<(std::ostream& out, const bigint& rhs){
    bool controlVariable = false; // This is used in order to prevent printing preceding 0's
    for (int i = 0; i < CAPACITY; ++i){
        if (rhs.numArray[i] != 0) controlVariable = true; // Hit the first non-preceding zero of bigint
        if (controlVariable) out << rhs.numArray[i]; // Fills the rest of the array with bigint
    }
    if (controlVariable == 0) out << rhs.numArray[CAPACITY - 1]; // This takes care of bigint being all 0's, 
    return out;                                                  // causing contorlVariable to never become true
}

bool bigint::operator==(const bigint& rhs) const {
    for (int i = 0; i < CAPACITY; ++i){
        if(numArray[i]!=rhs.numArray[i])
            return false;
    }
    return true;
}

std::istream& operator>>(std::istream& in, bigint& rhs) {
    char c;
    char arr[CAPACITY];
    in >> c;
    for (int i = 0; i < CAPACITY; ++i) {
        if (c == ';') {
            arr[i] = '\0';
            break;
        }
        arr[i] = c;
        in >> c;
    }
    rhs = bigint(arr);
    return in;
}

bigint bigint::operator+(const bigint& rhs) const {
    bigint sum;
    int carry = 0;
    for (int i = CAPACITY - 1; i >= 0; --i) {
        sum.numArray[i] = numArray[i] + rhs.numArray[i];
        sum.numArray[i] += carry;
        carry = 0;
        if (sum.numArray[i] > 9) {
        sum.numArray[i] = sum.numArray[i] % 10;
        carry = 1;
        }
    }
    return sum;
}

int bigint::operator[](int index) const { // 0 = CAPACITY - 1 ... 1 = CAPACITY - 2... etc..
    return numArray[CAPACITY - 1 - index];
}

bigint bigint::operator*(const bigint& rhs) const {
    bigint prod;
    int shift = 0;
    for (int i = CAPACITY - 1; i >=0; --i) {
        bigint temp;
        temp = timesDigit(rhs.numArray[i]);
        temp = temp.times10(shift);
        prod = prod + temp;
        ++shift;
    }
    return prod;
}

// ADD MORE TEST CASES
bigint bigint::timesDigit(int digit) const {
    bigint prod;
    int carry = 0;
    for (int i = CAPACITY - 1; i >= 0; --i) {
        prod.numArray[i] = numArray[i] * digit + carry;
        carry = 0;
        if (prod.numArray[i] > 9) {
        carry = prod.numArray[i] / 10;
        prod.numArray[i] = prod.numArray[i] % 10;
        }
    }
    return prod;
}

// ADD MORE TEST CASES
bigint bigint::times10(int shift) const {
    bigint shiftedBigInt;
    for (int i = CAPACITY - 1; i >= 0; --i) {
        shiftedBigInt.numArray[i - shift] = numArray[i];
    }
    return shiftedBigInt;
}