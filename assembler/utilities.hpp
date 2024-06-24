#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "stack.hpp"
#include "../string/string.hpp"
#include <iostream>
#include <fstream>

stack<String> get_infix(const char[]);

stack<String> infix_to_postfix(const char[]);


String eval(String, String, String, char, char&, char&);


String postfix_to_assembly(String);


//BONUS
stack<String> infix_to_prefix(const char[]);
String prefix_to_assembly(String);

#endif

