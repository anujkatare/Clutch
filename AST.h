#pragma once
#include <string>
#include <memory>
#include <vector>

// 1. Base Class
class ASTNode {
public:
    virtual ~ASTNode() = default; // Strict OOP standard for polymorphic cleanup
};

// 2. Base Class for Expressions
class ExprNode : public ASTNode {
public:
    virtual ~ExprNode() = default;
};

// 3. Literal Node
class NumberLiteralNode : public ExprNode {
public:
    std::string value;
    NumberLiteralNode(std::string val) : value(std::move(val)) {}
};

// 4. Variable Node
class VariableNode : public ExprNode {
public:
    std::string name;
    VariableNode(std::string nameStr) : name(std::move(nameStr)) {}
};

// 5. Binary Operation Node
class BinaryOpNode : public ExprNode {
public:
    std::string op; // "+", "-", "*", "/"
    std::unique_ptr<ExprNode> left;  // Smart pointer for automatic memory management
    std::unique_ptr<ExprNode> right;

    BinaryOpNode(std::string operation, std::unique_ptr<ExprNode> lhs, std::unique_ptr<ExprNode> rhs)
        : op(std::move(operation)), left(std::move(lhs)), right(std::move(rhs)) {}
};

// 6. Assignment Node
class AssignmentNode : public ASTNode {
public:
    std::string identifier;
    std::unique_ptr<ExprNode> value;

    AssignmentNode(std::string id, std::unique_ptr<ExprNode> val)
        : identifier(std::move(id)), value(std::move(val)) {}
};