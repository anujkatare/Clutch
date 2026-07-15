# ⚡ Clutch Programming Language

Clutch is a lightweight, modular, and interpreted programming language built from scratch using **Modern C++ (C++17/20)**. Designed with clean Object-Oriented Programming (OOP) principles and a zero-memory-leak guarantee, Clutch compiles and evaluates source code through a transparent **4-Pillar Compiler Pipeline**.

---

## 🚀 Features (Current Version)
* **Mathematical Expressions:** Full arithmetic evaluation with operator precedence (+, -, *, /).
* **Variable Assignment:** Dynamic runtime memory allocation and symbol mapping (score = 100).
* **Zero Memory Leaks:** Powered entirely by standard smart pointers (std::unique_ptr).
* **Cross-Platform & Lightweight:** Zero external dependencies. Runs seamlessly on Windows, macOS, Linux, and Docker environments.

---

## 🛠️ Quick Start & Execution Guide

Depending on your operating system and terminal, the syntax to execute compiled binaries differs slightly. Once you compile the compiler using g++, follow the instructions below for your specific terminal.

### 1. Compilation Command (All Platforms)
Open your terminal in the project root directory and run:

g++ main.cpp Lexer.cpp Parser.cpp Evaluator.cpp -o clutch

*(Note: On Windows, this will automatically generate clutch.exe)*

### 2. Running a Script (test.clt) on Different Terminals

#### 🖥️ Git Bash / MINGW64 (Windows/Linux/macOS)
In Bash-based terminals, you must use a forward slash ./ to execute a local binary:

./clutch test.clt

#### ⚡ Windows PowerShell (Default VS Code Terminal)
PowerShell requires a backslash .\ to invoke local executables for security reasons:

.\clutch test.clt

#### 🔲 Windows Command Prompt (CMD)
In legacy Windows Command Prompt, you can invoke the executable directly without prefix slashes:

clutch test.clt

#### 🐳 Docker / Dev Container
If you are using the integrated Dev Container, the binary is pre-configured for a Linux environment:

./clutch test.clt

---

## 🗺️ Roadmap & Future Features

Clutch is actively evolving! Here is our development roadmap for upcoming releases:
- [ ] **Data Types:** Support for Floating-point numbers (float), Strings ("hello"), and Booleans (true/false).
- [ ] **Built-in Keywords:** Implementing standard I/O commands like print() and input().
- [ ] **Control Flow:** Adding conditional branching (if, else if, else) and relational operators (==, <, >).
- [ ] **Loops:** Implementing while and for loop structures.
- [ ] **Functions:** Supporting user-defined functions with parameters and return scopes.
- [ ] **Error Recovery:** Enhanced syntax and line-number error reporting during parsing.

---

## 📂 Project Architecture & File Breakdown

This section details the purpose, programming language, and architectural role of every file within the compiler pipeline.

### 🌳 Directory Layout
Clutch/
├── .devcontainer/        <-- Docker environment configuration for VS Code
│   └── devcontainer.json
├── .github/              <-- CI/CD Workflows for automated GitHub testing
├── Dockerfile            <-- Container recipe for dependency-free setup
├── Lexer.h               <-- C++ Header: Token definitions and lexical analysis class
├── Lexer.cpp             <-- C++ Implementation: Stream scanning and character grouping
├── AST.h                 <-- C++ Header: Polymorphic Abstract Syntax Tree node classes
├── Parser.h              <-- C++ Header: Syntactic validation and tree-building class
├── Parser.cpp            <-- C++ Implementation: Recursive descent parsing algorithms
├── Evaluator.h           <-- C++ Header: Runtime memory state and symbol table
├── Evaluator.cpp         <-- C++ Implementation: Tree-walking interpreter logic
├── main.cpp              <-- C++ Implementation: CLI Entry point and pipeline orchestrator
├── test.clt              <-- Custom Script: Sample Clutch code for testing
└── README.md             <-- Markdown: This absolute documentation guide

### 🔍 Detailed File Analysis

#### 1. main.cpp (The Orchestrator)
* **Language:** C++
* **Purpose:** Acts as the Command Line Interface (CLI) entry point for the compiler. It handles file reading and passes data sequentially through the 4 core pillars: Source Code -> Lexer -> Parser -> Evaluator.

#### 2. Lexer.h & Lexer.cpp (Phase 1: Tokenization)
* **Language:** C++
* **Purpose:** Converts raw text characters into meaningful language tokens (TokenType Enum and Token Struct) using cursor-based scanning (peek() and advance()).

#### 3. AST.h (Phase 2: Data Modeling)
* **Language:** C++
* **Purpose:** Defines the structural hierarchy of the code using OOP Inheritance. Uses std::unique_ptr exclusively to model expression nodes (BinaryOpNode, NumberLiteralNode, etc.) with zero risk of memory leaks.

#### 4. Parser.h & Parser.cpp (Phase 3: Syntactic Analysis)
* **Language:** C++
* **Purpose:** Analyzes tokens using the Recursive Descent Parsing technique to build a mathematically accurate syntax tree, validating expression precedence and correct assignment formatting.

#### 5. Evaluator.h & Evaluator.cpp (Phase 4: Runtime Execution)
* **Language:** C++
* **Purpose:** Manages the system's runtime memory via a Symbol Table (std::unordered_map). It dynamically checks nodes, resolves values, handles runtime mathematics, and prints the final state.

---

## 🤝 Contributing & Developer Setup Guide

We welcome open-source contributors! To set up your environment smoothly:

### Method 1: Local Native Setup (Host Machine)
Ensure you have a C++17/20 compatible compiler installed:
* **Windows:** Install MinGW-w64.
* **macOS:** Run xcode-select --install.
* **Linux:** Run sudo apt-get install build-essential g++ git.

### Method 2: Docker Dev Container Setup (Recommended!)
1. Install Docker Desktop, VS Code, and the Dev Containers extension.
2. Open the cloned project folder in VS Code, press F1, select Dev Containers: Reopen in Container.
3. The environment will auto-build the Linux image and pre-compile the binary!

### 💻 Contribution Coding Standards
1. **Zero Memory Leaks:** Never use raw pointers with manual new or delete. Always use modern C++ smart pointers (std::unique_ptr).
2. **Strict Encapsulation:** Class variables must remain private. Expose functionality only through explicit public mechanisms.
3. **No Dead Code:** Remove commented-out lines and redundant header includes before committing.
4. **Descriptive PRs:** Ensure your code compiles cleanly without warnings, add a .clt verification test script, and open a Pull Request!


---

## 🚀 Next Step for Contributors: Ready to Code?

> ⚠️ **ATTENTION DEVELOPERS:** If you have successfully set up the environment on your local machine or via Docker Desktop, you are ready to make your first contribution! 

Please navigate directly to the **Contribute.md** file in the root directory. Inside, you will find a crystal-clear, step-by-step workflow tracking exactly how to:
1. Fork the repository and cut a clean feature branch.
2. Edit the corresponding C++ sub-systems without creating redundant files.
3. Test your code adjustments on different terminals using `test.clt`.
4. Open a structured Pull Request matching the project's production OOP standards.

Let's build the future of Clutch together! 🛠️