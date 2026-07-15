## 🛠️ Feature Implementation Guide: How to Extend Clutch

Clutch is designed with a highly modular architecture. When adding a new feature (such as a `print` statement, strings, or `if/else` control flow), contributors do not need to create new files. Instead, you will follow the **4-Pillar Pipeline** and extend the existing core files sequentially:

### 📑 Step 1: `Lexer.h` & `Lexer.cpp` (Phase 1: Token Recognition)
First, you must teach the compiler how to recognize the new word or syntax as a legal construct.
* **Where to go:** The `TokenType` enum inside `Lexer.h`.
* **What to write:** Add your new token identifier name (e.g., `PRINT`).
* **Inside `Lexer.cpp`:** Update the keyword lookup or scanning logic with a new condition. For example, if the scanner encounters the text `"print"`, it should match it and return `TokenType::PRINT`.

### 📑 Step 2: `AST.h` (Phase 2: Data Modeling)
Next, create a data model to represent the structural properties of your new feature in memory.
* **Where to go:** Scroll to the bottom of `AST.h`.
* **What to write:** Extend the tree by creating a new polymorphic class inheriting from `ASTNode` (for standalone statements) or `ExprNode` (for things that evaluate to a value).
* **Example Structure:**
  class PrintStatementNode : public ASTNode {
  public:
      std::unique_ptr<ExprNode> expression; // The expression to be printed
      PrintStatementNode(std::unique_ptr<ExprNode> expr) : expression(std::move(expr)) {}
  };

### 📑 Step 3: `Parser.h` & `Parser.cpp` (Phase 3: Syntactic Rules)
Define the grammatical rules for how tokens should structure themselves into the program tree.
* **Where to go:** Declare a parsing method in `Parser.h` and implement it in `Parser.cpp`.
* **What to write:** Add a conditional check inside the master `parse()` loop. When the parser encounters `TokenType::PRINT`, it should call your new method (e.g., `parsePrintStatement()`). This method will consume the tokens, build your `PrintStatementNode`, and push it into the AST program list.

### 📑 Step 4: `Evaluator.cpp` (Phase 4: Runtime Execution)
The final step defines the real-world action that executes on the host machine (Windows/Linux/macOS).
* **Where to go:** Inside the main statement execution loop of `Evaluator.cpp`.
* **What to write:** Use modern C++ `dynamic_cast` to safely inspect the node type at runtime. Extract its properties, compute any underlying values, and execute the behavior.
* **Example Structure:**
  if (auto* printNode = dynamic_cast<PrintStatementNode*>(node.get())) {
      int val = evaluateExpr(printNode->expression.get());
      std::cout << val << std::endl; // Dynamically prints the computed value to the terminal screen!
  }