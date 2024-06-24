#include "utilities.hpp"




int main(int argc, const char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " input_file [output_file]" << std::endl;
        return 1;
    }

    stack<String> result;
    stack<String> infix;
    String assembler;
    result = infix_to_prefix(argv[1]);
    infix = get_infix(argv[1]);

    // Check if an output file is provided
    if (argc == 3) {
        std::ofstream out(argv[2]);
        if (!out) {
            std::cout << "Error opening output file " << argv[2] << std::endl;
            return 1;
        }
        while (!result.empty()) {
            String prefix = result.pop();
            out << "Infix Expression: " << infix.pop() << std::endl;
            out << "Postfix Expression: " << prefix << std::endl;
            String assembly = prefix_to_assembly(prefix);
            out << assembly << std::endl;
        }
        out.close();
    } else { // No output file provided, print result to screen
        while (!result.empty()) {
            String prefix = result.pop();
            std::cout << "Infix Expression: " << infix.pop() << std::endl;
            std::cout << "Prefix Expression: " << prefix << std::endl << std::endl;
            prefix_to_assembly(prefix);
            std::cout << std::endl;
        }
    }
    
    return 0;
}
