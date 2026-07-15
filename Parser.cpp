#include "Parser.h"
#include <iostream>
#include <stdexcept>

Parser::Parser(std::vector<Token> tokensList) : tokens(std::move(tokensList)), cursor(0) {}

Token Parser::peek() const {
    if (cursor >= tokens.size()) return {TokenType::EOF_TOKEN, ""};
    return tokens[cursor];
}

Token Parser::advance() {
    if (cursor < tokens.size()) cursor++;
    return tokens[cursor - 1];
}

bool Parser::match(TokenType type) {
    if (peek().type == type) {
        advance();
        return true;
    }
    return false;
}

Token Parser::consume(TokenType type, const std::string& errorMessage) {
    if (peek().type == type) return advance();
    throw std::runtime_error("Syntax Error: " + errorMessage + " Got '" + peek().value + "'");
}

// Low-level expressions: Numbers or Identifiers
std::unique_ptr<ExprNode> Parser::parsePrimary() {
    if (match(TokenType::NUMBER)) {
        return std::make_unique<NumberLiteralNode>(tokens[cursor - 1].value);
    }
    if (match(TokenType::IDENTIFIER)) {
        return std::make_unique<VariableNode>(tokens[cursor - 1].value);
    }
    throw std::runtime_error("Syntax Error: Expected expression, got '" + peek().value + "'");
}

// Operator Precedence: Handles Basic Binary Ops (+, -, *, /)
std::unique_ptr<ExprNode> Parser::parseExpression() {
    std::unique_ptr<ExprNode> expr = parsePrimary();

    while (peek().type == TokenType::PLUS || peek().type == TokenType::MINUS ||
           peek().type == TokenType::MULTIPLY || peek().type == TokenType::DIVIDE) {
        Token opToken = advance();
        std::unique_ptr<ExprNode> right = parsePrimary();
        expr = std::make_unique<BinaryOpNode>(opToken.value, std::move(expr), std::move(right)); // <-- Yahan make_make_unique fixed!
    }

    return expr;
}

// Master parsing loop that groups lines into structural nodes
std::vector<std::unique_ptr<ASTNode>> Parser::parse() {
    std::vector<std::unique_ptr<ASTNode>> program;

    while (peek().type != TokenType::EOF_TOKEN) {
        try {
            if (peek().type == TokenType::IDENTIFIER) {
                Token id = advance();
                if (match(TokenType::ASSIGN)) {
                    std::unique_ptr<ExprNode> expr = parseExpression();
                    program.push_back(std::make_unique<AssignmentNode>(id.value, std::move(expr)));
                    continue;
                }
                throw std::runtime_error("Expected '=' after variable identifier");
            }
            advance(); // Skip if unhandled token for safety
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            exit(1); 
        }
    }
    return program;
}