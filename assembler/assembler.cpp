#include "utilities.hpp"


// the assembler code for prefix is in bonusAssembler.cpp

int main(int argc, const char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " input_file [output_file]" << std::endl;
        return 1;
    }

    stack<String> result;
    stack<String> infix;
    String assembler;
    result = infix_to_postfix(argv[1]);
    infix = get_infix(argv[1]);

    // Check if an output file is provided
    if (argc == 3) {
        std::ofstream out(argv[2]);
        if (!out) {
            std::cout << "Error opening output file " << argv[2] << std::endl;
            return 1;
        }
        while (!result.empty()) {
            String postfix = result.pop();
            out << "Infix Expression: " << infix.pop() << std::endl;
            out << "Postfix Expression: " << postfix << std::endl;
            String assembly = postfix_to_assembly(postfix);
            out << assembly << std::endl;
        }
        out.close();
    } else { // No output file provided, print result to screen
        while (!result.empty()) {
            String postfix = result.pop();
            std::cout << "Infix Expression: " << infix.pop() << std::endl;
            std::cout << "Postfix Expression: " << postfix << std::endl << std::endl;
            postfix_to_assembly(postfix);
            std::cout << std::endl;
        }
    }
    
    return 0;
}
