# ⚡ Clutch

> **Write fast. Execute faster. Built for developers who refuse to compromise on performance.**

`Clutch` is an open-source, next-generation programming language engineered from the ground up to deliver blazing-fast native execution speeds with an incredibly clean, minimalist syntax. It offers a premium developer experience, bringing high-octane performance directly to your fingertips without the overhead of heavy virtual machines.

---

## 🎮 Why Clutch?

*   **High-Octane Performance:** Compiled directly to run close to the metal with zero execution overhead.
*   **Aesthetic & Minimal Syntax:** No unnecessary boilerplate. Write clean, readable code effortlessly.
*   **Modern Core:** Built using standard C++ under the hood, ensuring top-tier speed, memory efficiency, and safety.
*   **Developer-First Ecosystem:** Designed for seamless tooling, quick setups, and absolute control.

---

## 🛠️ The Architecture (How it Works)

Clutch compiles your source files directly into optimized executables. The compiler pipeline is broken down into modular steps, making it incredibly easy for open-source contributors to jump in:

1.  **Lexer (Lexical Analyzer):** Breaks your raw code into readable tokens.
2.  **Parser:** Analyzes the tokens and builds an Abstract Syntax Tree (AST) representing the program's logic.
3.  **Code Generator:** Translates the AST directly into highly optimized target code for execution.

---

## 🚀 Quick Start & Development Setup

To make contributing as painless as possible, the entire development environment is containerized. This means you do not need to struggle with installing complex C++ compilers, CMake, or dependencies locally on your machine. 

### Prerequisites
Make sure you have the following installed on your machine:
*   [Git](https://git-scm.com/)
*   [VS Code](https://code.visualstudio.com/)
*   [Docker Desktop](https://www.docker.com/products/docker-desktop/)

---

### Option A: The 1-Click Setup (Highly Recommended)
We use VS Code **Dev Containers** to automatically configure your workspace inside Docker.

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YOUR_GITHUB_USERNAME/clutch.git](https://github.com/YOUR_GITHUB_USERNAME/clutch.git)
    cd clutch
    ```
2.  **Open in VS Code:**
    ```bash
    code .
    ```
3.  **Reopen in Container:**
    *   VS Code will automatically detect the configuration and show a pop-up in the bottom-right corner: *"Folder contains a Dev Container configuration. Reopen in Container."*
    *   Click **Reopen in Container**.
    *   *Alternatively:* Open the Command Palette (`Ctrl+Shift+P` on Windows/Linux or `Cmd+Shift+P` on Mac) and type: `Dev Containers: Reopen in Container`.

VS Code will now download the exact compiler environment, install the C++ and CMake extensions automatically, and set up your environment inside Docker. **You are ready to code!**

---

### Option B: Manual Docker Setup
If you prefer using the terminal directly with Docker:

1.  **Build the Docker Image:**
    ```bash
    docker build -t clutch-dev .
    ```
2.  **Run the Interactive Container:**
    ```bash
    docker run -it -v $(pwd):/workspace clutch-dev
    ```

---

### Option C: Bare Metal Setup (No Docker)
If you prefer compiling directly on your host machine, ensure you have a modern compiler (**C++20** compatible) and **CMake** installed.

```bash
# 1. Generate the build configuration
cmake -B build

# 2. Compile the project
cmake --build build

# 3. Run the Clutch compiler binary
./build/clutch
