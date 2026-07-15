#pragma once
#include <string>
#include <vector>

enum class TokenType {
    NUMBER,
    IDENTIFIER,
    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EOF_TOKEN,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string source;
    size_t cursor;

    char peek() const;
    char advance();

public:
    Lexer(const std::string& src);
    std::vector<Token> tokenize();
};