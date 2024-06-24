#include "../assembler/stack.hpp"
#include "../string/string.hpp"
#include <iostream>
#include <fstream>


// Returns a stack full of prefix expressions when
// passed a file name with proper infix epressions.
stack<String> infix_to_prefix(const char[]);


int main() {
    String s;
    stack<String> result;
    result = infix_to_prefix("data3-1.txt");

    while (!result.empty()) {
        s = result.pop();
        std::cout << s << std::endl;
    }

    return 0;
}


//expr - must be valid fully paranthesised infix expression
stack<String> infix_to_prefix(const char fileName[100]) {
    stack<String> S;
    String rhs, lhs, op;
    String expr;
    int i = 0;
    std::ifstream in(fileName);
    in >> expr; 
    while (!in.eof()) {
        while (expr != ';') {
            if (expr == ')') {
                rhs = S.pop();
                op  = S.pop();
                lhs = S.pop();
                //S.push(lhs + rhs + op); // POSTFIX
                S.push(op + " " + lhs + " " + rhs);   // PREFIX
            } else if (expr != '(') {
                S.push(expr);
            }
            in >> expr;
        }
        in >> expr;
    }
    // Reorder S so it is in the same order as the file input
    String temp;
    stack<String> reorderedS;
    while (!S.empty()) {
        temp = S.pop();
        reorderedS.push(temp);
    }
    return reorderedS;
}


