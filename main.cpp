#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"

int main(int argc, char* argv[]) {
    // 1. Check valid arguments (clutch <filename.clt>)
    if (argc < 2) {
        std::cout << "Error: No input file specified.\n";
        std::cout << "Usage: clutch <filename.clt>\n";
        return 1;
    }

    std::string filename = argv[1];

    // 2. Validate .clt extension
    if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".clt") {
        std::cout << "Error: Invalid file extension. Clutch source files must end with '.clt'\n";
        return 1;
    }

    // 3. Read the .clt source file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file '" << filename << "'\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sourceCode = buffer.str();

    std::cout << "Clutch Compiler: Running '" << filename << "'...\n\n";

    // 4. Tokenize the code using our C++ Lexer
    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.tokenize();

    // Temporarily print tokens for debugging
    std::cout << "--- [Tokens Found] ---\n";
    for (const auto& token : tokens) {
        if (token.type == TokenType::EOF_TOKEN) break;
        std::cout << "Value: '" << token.value << "'\n";
    }

    return 0;
}