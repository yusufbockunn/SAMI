# SAMI 🚀

**SAMIENGINE** is my personal journey into building a fully functional game engine from scratch.  
It’s a work-in-progress engine designed to explore how modern rendering, entity systems, logging, and other core systems come together under the hood.

This is not just a codebase — it’s a learning experience. I'm building this to understand:

- How rendering pipelines really work
- How ECS (Entity Component System) can be implemented
- How to build flexible logging tools
- And eventually: how a game engine ties all systems together into something playable

---

## Getting Started

To get started with building and running **SAMIENGINE**, follow the instructions below.

### 📋 Prerequisites

Before building the project, make sure you have the following installed:

- **[Visual Studio 2022](https://visualstudio.microsoft.com/downloads/)** (or any IDE that supports CMake)
- **[CMake](https://cmake.org/download/)** (CMake version 3.10 or higher)
- **[Git](https://git-scm.com/)** (to clone the repository)

Make sure that Visual Studio is configured with the **Desktop development with C++** workload.

### 🔄 Cloning the Project

Clone the project to your local machine by running:

```bash
git clone https://github.com/yusufbockunn/SAMI.git
cd SAMI
git submodule update --init --recursive

```

### ⚙️ Setup Project

Clone the project to your local machine by running:

```bash
git clone https://github.com/yusufbockunn/SAMI.git
cd SAMI
git submodule update --init --recursive
```

After that open SAMI folder and open Command Line and write:

```bash
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
cmake --build . --config Debug
```

### 🚀 Running Project

After a successful build, you can navigate to the output directory and run the SandBox executable.

For Debug configuration, the output will be at:

```bash
build/bin/Debug-x64/SandBox/SandBox.exe
```
