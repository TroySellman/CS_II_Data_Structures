#include "string.hpp"
#include <cassert>


String::String() {
    str[0] = 0;
}

String::String(char ch) {
    str[0] = ch;
    str[1] = 0;
}

String::String(const char s[]) {
    int i = 0;
    while (s[i] != 0){
        if(i >= capacity()) break;
        str[i] = s[i];
        ++i;
    }
    str[i] = 0;
}

int String::capacity() const {
    return STRING_SIZE - 1;
}

int String::length() const {
    int result = 0;
    while (str[result] != 0) ++result;
    return result;
}

// REQUIRES 0 <= i < length()
char String::operator[](int i) const {
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
    int i = 0;
    while (i < rhsLength) {
        if (offset + i >= capacity()) break;
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = 0;
    return *this;
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

String operator+(String lhs, const String& rhs) {
    return lhs += rhs;
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
    char buffer[STRING_SIZE];
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
    String result;
    int i = begin;
    while (i <= end) {
        result.str[i - begin] = str[i];
        ++i;
    }
    result.str[i - begin] = 0;
    return result;
}

//findch(int start, char ch) - returns location of ch at or after start, returns -1 if not found
//findstr(int start, cosnt String& str) - returns the location of str at or after start, returns -1 if not found.
int String::findch(int start,  char ch) const { //Location of charater starting at a position
    for (int i = start; i < STRING_SIZE; ++i) {
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

