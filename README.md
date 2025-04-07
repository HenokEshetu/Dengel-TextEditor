# Dengel Text Editor

Dengel Text Editor is designed to interact with text files simply like notepad using C++23.

## Pre-requesit

### Build System

-   CMake - v3.14.0 or latest
-   Premake5 - v5.0.0beta6 or latest

### Compiler

-   clang++ - v16 or latest
-   g++ - v13 or latest

## How to build?

### CMake

To build this project using cmake, first you need to create a directory called `build` on the parent directory and by get into that path you can generate `cmake` build files.

CMake it mostly preferable for unix systems as it is fully supported by it very much for decades.

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

### Premake5

Using premake5 you can generate/build different projects such as vs2019, vs2022, gmake, gmake2, ... and more which is very flexible and ideal for windows and mac.

-   For Visual Studio Project `premake5 vs2022` or `premake5 vs2019` based on your Visual Studio version.
-   For Makefile `premake5 gmake` or `premake5 gmake2`
-   For Xcode `premake5 xcode`
