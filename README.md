# C++ Meson build template
This is a template for C++ projects using the Meson build system. It includes Gtest as an external dependency which is automatically downloaded 
by Meson's WrapDB.  

## Requirements
* A C++ compiler that supports at least C++17
* Meson build

## Optional
* Clang-tidy (for static analysis of code)
* Clang-format

## Getting started
To compile the code, change the directory to the project root (where README.md is located), and type the following: 
    
    meson setup builddir
    cd builddir
    meson compile

To run tests:

    cd builddir
    meson test

To run clang tidy, or clang-format (assuming those are installed):

    cd builddir
    ninja clang-format
    ninja clang-tidy

