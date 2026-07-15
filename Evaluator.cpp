#include "Evaluator.h"
#include <iostream>
#include <stdexcept>

int Evaluator::evaluateExpr(ExprNode* expr) {
    if (!expr) return 0;

    
    if (auto* numNode = dynamic_cast<NumberLiteralNode*>(expr)) {
        return std::stoi(numNode->value);
    }

    
    if (auto* varNode = dynamic_cast<VariableNode*>(expr)) {
        if (environment.find(varNode->name) == environment.end()) {
            throw std::runtime_error("Runtime Error: Variable '" + varNode->name + "' is undefined!");
        }
        return environment[varNode->name];
    }


    if (auto* binOp = dynamic_cast<BinaryOpNode*>(expr)) {
        int leftVal = evaluateExpr(binOp->left.get());
        int rightVal = evaluateExpr(binOp->right.get());

        if (binOp->op == "+") return leftVal + rightVal;
        if (binOp->op == "-") return leftVal - rightVal;
        if (binOp->op == "*") return leftVal * rightVal;
        if (binOp->op == "/") {
            if (rightVal == 0) throw std::runtime_error("Runtime Error: Division by zero!");
            return leftVal / rightVal;
        }
    }

    return 0;
}

void Evaluator::evaluate(const std::vector<std::unique_ptr<ASTNode>>& program) {
    for (const auto& node : program) {
        
        if (auto* assignNode = dynamic_cast<AssignmentNode*>(node.get())) {
            int value = evaluateExpr(assignNode->value.get());
            environment[assignNode->identifier] = value;
        }
    }
}

void Evaluator::printEnvironment() const {
    std::cout << "\n--- [Execution Output / Memory State] ---\n";
    if (environment.empty()) {
        std::cout << "Memory is empty.\n";
        return;
    }
    for (const auto& pair : environment) {
        std::cout << "Variable: " << pair.first << " => Value: " << pair.second << "\n";
    }
}