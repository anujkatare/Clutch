#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include "AST.h"

class Evaluator {
private:
    // Symbol Table
    std::unordered_map<std::string, int> environment;

    // Helper evaluation methods for expressions
    int evaluateExpr(ExprNode* expr);

public:
    void evaluate(const std::vector<std::unique_ptr<ASTNode>>& program);
    void printEnvironment() const; 
};