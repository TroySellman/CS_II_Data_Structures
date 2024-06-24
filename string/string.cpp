#include "string.hpp"
#include <cassert>

// Empty String
String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

// String ('x')
String::String(char ch) {
    if (ch == '\0') {
        stringSize = 1;
        str = new char[stringSize];
        str[0] = '\0';
    } else {
        stringSize = 2;
        str = new char[stringSize];
        str[0] = ch;
        str[1] = '\0';
    }
}

// String("abc")
String::String(const char charArray[]) {
    int length = 0;
    while (charArray[length] != 0) ++length; 
    stringSize = length + 1;
    str = new char[stringSize];
    for (int i = 0; i < length; ++i) str[i] = charArray[i];
    str[length] = '\0';
}

// Copy Constructor
String::String(const String& actual) {
    stringSize = actual.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize - 1; ++i) str[i] = actual.str[i];
    str[stringSize - 1] = '\0';
}

//Destructor
String::~String() {
    delete[] str;
    stringSize = 0;
}

// Constant time swap
void String::swap(String& rhs) {
    // swaps ptr
    char *temp = str;
    str        = rhs.str;
    rhs.str    = temp;
    // swaps size
    int tempSize     = stringSize;
    stringSize       = rhs.stringSize;
    rhs.stringSize   = tempSize;
}

// Assignment Copy
String& String::operator=(String rhs) {
    swap(rhs);
    return *this;
}


int String::capacity() const {
    return length();
}

int String::length() const {
    int result = 0;
    while (str[result] != 0) ++result;
    return result;
}

// REQUIRES 0 <= i < length()
char String::operator[](int i) const{
    assert(i >= 0);
    assert(i < length());
    return str[i];
}

// REQUIRES 0 <= i < length()
char& String::operator[](int i) {
    assert(i >= 0);
    assert(i < length());
    return str[i];
}

String& String::operator+=(const String& rhs) {
    int offset = length();
    int rhsLength = rhs.length();
    stringSize = offset + rhsLength + 1;
    char *ptr = new char[stringSize];
    int i = 0;
    while (i < offset) {
        ptr[i] = str[i];
        ++i;
    }
    int j = 0;
    while (j < rhsLength) {
        ptr[i] = rhs.str[j];
        ++j;
        ++i;
    }
    ptr[i] = '\0';
    delete[] str;
    str = ptr;
    return *this;
}

String operator+(String lhs, const String& rhs) {
    return lhs += rhs;
}

bool String::operator==(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] == rhs.str[i];
}

bool String::operator<(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}


bool   operator<  (char lhs, const String& rhs)          { return String(lhs) < rhs;  }
bool   operator<  (const char lhs[], const String& rhs)  { return String(lhs) < rhs;  }
bool   operator== (char lhs, const String& rhs)          { return String(lhs) == rhs; }
bool   operator== (const char lhs[], const String& rhs)  { return String(lhs) == rhs; }
bool   operator!= (const String& lhs, const String& rhs) { return !(lhs == rhs);      }
bool   operator>  (const String& lhs, const String& rhs) { return rhs < lhs;          }
bool   operator>= (const String& lhs, const String& rhs) { return !(lhs < rhs);       }
bool   operator<= (const String& lhs, const String& rhs) { return !(rhs < lhs);       }

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}



std::istream& operator>>(std::istream& in, String& rhs) {
    char buffer[rhs.stringSize];
    if (!in.eof()) { 
        in >> buffer;
    } else {
        buffer[0] = 0;
    }
    rhs = String(buffer);
    return in;
}



//REQUIRES: 0 <= begin <= end < length()
String String::substr (int begin, int end) const {
    if (begin < 0) begin = 0;
    if (end >= length()) end = length() - 1;
    if (begin > end) return String();
    int subStringSize = end - begin + 2;
    char *ptr = new char[subStringSize];
    int i = begin;
    while (i <= end) {
        ptr[i - begin] = str[i];
        ++i;
    }
    ptr[i - begin] = 0;
    String result(ptr);
    return result;
}


int String::findch(int start,  char ch) const { //Location of charater starting at a position
    for (int i = start; i < stringSize; ++i) {
        if(str[i] == ch) return i;
    }
    return -1;
}

int String::findstr(int start, const String& string)const{
  if (start < 0) start = 0;
  if (start > length() - string.length()) return -1;
  int length = string.length();
  int i = start;
  while(str[i] != 0){
    if(substr(i, i + length - 1) == string) return i;
    ++i;
  }
  return -1;
}


//s = "abc ef gh", then s.split(' ') returns a vector with three strings: { "abc", "ef", "gh" }
//s = "-a--b-", then s.split('-') returns a vector with five strings: { "", "a", "", "b", "" }, three of which are empty string.
std::vector<String> String::split(char splitVar) const {
    std::vector<String> result;
    int start = 0;
    int pos = findch(start, splitVar);
    while (pos != -1) {
        result.push_back(substr(start, pos - 1));
        start = pos + 1;
        pos = findch(start, splitVar);
    }
    result.push_back(substr(start, stringSize));
    return result;
}