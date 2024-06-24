#include "stack.hpp"
#include "../string/string.hpp"
#include <iostream>
#include <fstream>



stack<String> get_infix(const char fileName[100]) {
    stack<String> S;
    String infix;
    String expr;
    std::ifstream in(fileName);
    if(!in) {
        std::cout << "Error Opening: " << fileName << std::endl;
        return S;
    }
    in >> expr; 
    while (!in.eof()) {
        while (expr != ';') {
            infix += expr + " ";
            in >> expr;
        }
        S.push(infix);
        in >> expr;
        infix = "";
    }
    // Reorder S so it is in the same order as the input file
    stack<String> reorderedS;
    while (!S.empty()) {
        reorderedS.push(S.pop());
    }
    return reorderedS;
}



stack<String> infix_to_postfix(const char fileName[100]) {
    stack<String> S;
    String rhs, lhs, op;
    String expr;
    std::ifstream in(fileName);
    if(!in) {
        std::cout << "Error Opening: " << fileName << std::endl;
        return S;
    }
    in >> expr; 
    while (!in.eof()) {
        while (expr != ';') {
            if (expr == ')') {
                rhs = S.pop();
                op  = S.pop();
                lhs = S.pop();
                S.push(lhs + " " + rhs + " " + op); // POSTFIX
            } else if (expr != '(') {
                S.push(expr);
            }
            in >> expr;
        }
        in >> expr;
    }
    // Reorder S so it is in the same order as the input file
    stack<String> reorderedS;
    while (!S.empty()) {
        reorderedS.push(S.pop());
    }
    return reorderedS;
}



String eval(String lhs, String rhs, String operation, char STcounter, char &lhsTMPcounter, char &rhsTMPcounter) {
    bool lhsIsTMP = false;
    bool rhsIsTMP = false;
    String TMPvar = lhs + " " + operation + " " + rhs;
    char op = operation[0];
    String opCode;
    switch(op) {
        case '+': opCode = "AD"; break;
        case '-': opCode = "SB"; break;
        case '*': opCode = "MU"; break;
        case '/': opCode = "DV";
    }

    if (STcounter == '1'){
        std::cout << "Opcode\t" << "Operand\t" << "Comment\n";
    }
    // check if lhs is TMP
    for (int i = 0; i < lhs.capacity(); ++i) {
        if (lhs[i] == '+' || lhs[i] == '-' || lhs[i] == '*' || lhs[i] == '/') { 
            lhsIsTMP = true;
        }
    }

    // check if rhs is TMP
    for (int i = 0; i < rhs.capacity(); ++i) {
        if (rhs[i] == '+' || rhs[i] == '-' || rhs[i] == '*' || rhs[i] == '/') {
            rhsIsTMP = true;
        }
    }

    if (lhsIsTMP) lhsTMPcounter += 1;
    if (rhsIsTMP) rhsTMPcounter += 1;
    //if (lhsTMPcounter == '0' && rhsTMPcounter == '0' && STcounter > '1') rhsTMPcounter += 1;
    //std::cout << "\nlhs: " << lhsTMPcounter << " rhs: " << rhsTMPcounter << " ST: " << STcounter << "\n";

    if (rhsIsTMP && lhsIsTMP) {
        std::cout << "LD\t" << "TMP" << rhsTMPcounter << "\tGet " << lhs << ".\n";
    } else if (lhsIsTMP) {
        std::cout << "LD\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tGet " << lhs << ".\n";
    } else std::cout << "LD\t" << lhs << "\tLoad in " << lhs << ".\n";

    if (rhsIsTMP && lhsIsTMP) {
        //std::cout << "\n if1 \n";
        if (opCode == "AD") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tAdd " << rhs << " to it.\n";
        }
        if (opCode == "SB") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tSubtract " << rhs << " from it.\n";
        }
        if (opCode == "MU") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tMultiply it by " << rhs << ".\n";
        }
        if (opCode == "DV") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tDivide it by " << rhs << ".\n";
        }
    } else if (rhsIsTMP) {
        //std::cout << "\n if2 \n";
        if (opCode == "AD") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tAdd " << lhs << " to " << rhs << ".\n";
        }
        if (opCode == "SB") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tSubtract " << rhs << " from " << lhs << ".\n";
        }
        if (opCode == "MU") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tMultiply " << lhs << " by " << rhs << ".\n";
        }
        if (opCode == "DV") {
            std::cout << opCode << "\t" << "TMP" << (lhsTMPcounter - '0') + (rhsTMPcounter - '0') << "\tDivide " << lhs << " by " << rhs << ".\n";
        }
    } else if (lhsIsTMP) {
        //std::cout << "\n if3 \n";
        if (opCode == "AD") {
            std::cout << opCode << "\t" << rhs << "\tAdd " << rhs << " to it.\n";
        }
        if (opCode == "SB") {
            std::cout << opCode << "\t" << rhs << "\tSubtract " << rhs << " from it.\n";
        }
        if (opCode == "MU") {
            std::cout << opCode << "\t" << rhs << "\tMultiply it by " << rhs << ".\n";
        }
        if (opCode == "DV") {
            std::cout << opCode << "\t" << rhs << "\tDivide it by " << rhs << ".\n";
        }
    } else {
        //std::cout << "\n if4 \n"; 
        std::cout << opCode << "\t" << rhs << "\t" << lhs << " " << operation << " " << rhs << ".\n";
    }
    lhsIsTMP = false;
    rhsIsTMP = false;
    std::cout << "ST\t" << "TMP" << STcounter << "\tSave results of " << lhs << " " << operation << " " << rhs << ".\n";

    return TMPvar;
}

String postfix_to_assembly(String expr) {
    stack<String> S;
    char STcounter = '1';
    char lhsTMPcounter = '0';
    char rhsTMPcounter = '0';
    String assembly, rhs, lhs;
    std::vector<String> splitExpr = expr.split(' ');
    for (size_t i = 0; i < splitExpr.size(); ++i) {
        if (splitExpr[i] != '+' && splitExpr[i] != '-' && splitExpr[i] != '*' && splitExpr[i] != '/') {
            S.push(splitExpr[i]);
        } else {
            rhs = S.pop();
            lhs = S.pop();
            String result = eval(lhs, rhs, splitExpr[i], STcounter, lhsTMPcounter, rhsTMPcounter);
            S.push(result);
            STcounter += 1;
            assembly += result;
        }
    }
    return assembly;
}






//BONUS
//The only difference between the two functions is a single line of code
//you only have to change the order you push op, lhs, rhs
stack<String> infix_to_prefix(const char fileName[100]) {
    stack<String> S;
    String rhs, lhs, op;
    String expr;
    std::ifstream in(fileName);
    if(!in) {
        std::cout << "Error Opening: " << fileName << std::endl;
        return S;
    }
    in >> expr; 
    while (!in.eof()) {
        while (expr != ';') {
            if (expr == ')') {
                rhs = S.pop();
                op  = S.pop();
                lhs = S.pop();
                S.push(op + " " + lhs + " " + rhs); // PREFIX
            } else if (expr != '(') {
                S.push(expr);
            }
            in >> expr;
        }
        in >> expr;
    }
    // Reorder S so it is in the same order as the file input
    stack<String> reorderedS;
    while (!S.empty()) {
        reorderedS.push(S.pop());
    }
    return reorderedS;
}

// Making the assembler for prefix was not too much different.
// I just had to loop through the entire vector first and then
// loop until the stack is empty while evaluating the assembler.
String prefix_to_assembly(String expr) {
stack<String> S;
    char STcounter = '1';
    char lhsTMPcounter = '0';
    char rhsTMPcounter = '0';
    String assembly, rhs, lhs;
    std::vector<String> splitExpr = expr.split(' ');
    for (size_t i = 0; i < splitExpr.size(); ++i) {
            S.push(splitExpr[i]);
    }
    while(!S.empty()) {
        rhs = S.pop();
        if (S.empty()) break;
        lhs = S.pop();
        if (S.empty()) break;
        String result = eval(lhs, rhs, S.pop(), STcounter, lhsTMPcounter, rhsTMPcounter);
        S.push(result);
        STcounter += 1;
        assembly += result;
    }
    return assembly;
}


