#include "utilities.hpp"

int main(int argc, const char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " input_file [output_file]" << std::endl;
        return 1;
    }

    stack<String> result;
    stack<String> infix;
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
            out << "Infix Expression: " << infix.pop() << std::endl;
            out << "Postfix Expression: " << result.pop() << std::endl;
        }
        out.close();
    } else { // No output file provided, print result to screen
        while (!result.empty()) {
            std::cout << "Infix Expression: " << infix.pop() << std::endl;
            std::cout << "Postfix Expression: " << result.pop() << std::endl << std::endl;
        }
    }
    
    return 0;
}
