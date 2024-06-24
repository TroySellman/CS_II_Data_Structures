// HEADER FOR BIGINT USE GUARDS


#include <iostream>
/*
const int CAPACITY = 200; // number of digits in the number
class bigint {
public:
    bigint();
    
private:
    int numArray[CAPACITY];
    
};
*/
// END OF BIGINT.HPP

//BIGINT.CPP START
#include "bigint.hpp"
// defualt constructors
bigint::bigint(){
    
}

bigint::bigint(int){
    
}

// END OF BIGIN.CPP


int main(){
    //for bigint::bigint(int)
    //loop this process until we reach 
  int number = 304;
  int digit = number % 10;
  number = number / 10;


    
}

// ASSIGNMENT 2


bigint::bigint(){
    return;
    //can leave them empty, 5 of the functions.
    //for (int i =0; i < CAPACITY; ++i)
     //   numberArray[i] = 0;
}

//bigint::bigint(const char charnumber[]){
//    return;
//}




// MILESTONE 2

// operator[] make test cases
/*

bigint num1;
std::cout << num1[2]; // 145 ---> 5

int operatpr[](int index) const;
*/

// ADDITION
/*
bigint operator+(const bigint&) const;
for (...)
int carry = 0;
n[i]+n2[i]+c // 15
if > 9
% 10 = 5
carry = 1;
else carry = 0;
*/

// operator>>
/*
char c;
in >> c;
for (...)
if (c == ';'){
    cArray[i] = '\0'
    break;
}
cArray[i]=c;
in >> c;

*/