#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Parser.h"
#include "Evaluator.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: No input file specified.\n";
        std::cout << "Usage: clutch <filename.clt>\n";
        return 1;
    }

    std::string filename = argv[1];
    if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".clt") {
        std::cout << "Error: Invalid file extension. Use '.clt'\n";
        return 1;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file '" << filename << "'\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sourceCode = buffer.str();

    std::cout << "⚡ Clutch Compiler: Running '" << filename << "'...\n";

    try {
        // 1. Tokenization Phase
        Lexer lexer(sourceCode);
        std::vector<Token> tokens = lexer.tokenize();

        // 2. Syntactic Parsing Phase
        Parser parser(tokens);
        std::vector<std::unique_ptr<ASTNode>> ast = parser.parse();

        // 3. Execution Runtime Phase
        Evaluator evaluator;
        evaluator.evaluate(ast);
        evaluator.printEnvironment();

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}