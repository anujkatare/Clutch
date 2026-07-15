#pragma once
#include <vector>
#include <memory>
#include "Lexer.h"
#include "AST.h"

class Parser {
private:
    std::vector<Token> tokens;
    size_t cursor;

    // Helper methods for moving through tokens safely
    Token peek() const;
    Token advance();
    bool match(TokenType type);
    Token consume(TokenType type, const std::string& errorMessage);

    // Grammar rules parsing methods
    std::unique_ptr<ExprNode> parseExpression();
    std::unique_ptr<ExprNode> parsePrimary();

public:
    Parser(std::vector<Token> tokensList);
    std::vector<std::unique_ptr<ASTNode>> parse();
};