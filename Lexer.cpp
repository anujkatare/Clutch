#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src), cursor(0) {}

char Lexer::peek() const {
    if (cursor >= source.length()) return '\0';
    return source[cursor];
}

char Lexer::advance() {
    if (cursor >= source.length()) return '\0';
    return source[cursor++];
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (cursor < source.length()) {
        char current = peek();

        if (std::isspace(current)) {
            advance();
            continue;
        }

        if (current == '=') { tokens.push_back({TokenType::ASSIGN, "="}); advance(); continue; }
        if (current == '+') { tokens.push_back({TokenType::PLUS, "+"}); advance(); continue; }
        if (current == '-') { tokens.push_back({TokenType::MINUS, "-"}); advance(); continue; }
        if (current == '*') { tokens.push_back({TokenType::MULTIPLY, "*"}); advance(); continue; }
        if (current == '/') { tokens.push_back({TokenType::DIVIDE, "/"}); advance(); continue; }

        if (std::isdigit(current)) {
            std::string numStr = "";
            while (std::isdigit(peek())) {
                numStr += advance();
            }
            tokens.push_back({TokenType::NUMBER, numStr});
            continue;
        }

        if (std::isalpha(current)) {
            std::string identStr = "";
            while (std::isalnum(peek())) {
                identStr += advance();
            }
            tokens.push_back({TokenType::IDENTIFIER, identStr});
            continue;
        }

        tokens.push_back({TokenType::UNKNOWN, std::string(1, advance())});
    }

    tokens.push_back({TokenType::EOF_TOKEN, ""});
    return tokens;
}