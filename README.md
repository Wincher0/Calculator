# Calculator
Basic Calculator Win App in C

A lightweight, native Windows calculator application written entirely in C using the standard Windows API (Win32). 

## Description
This project demonstrates how to create a basic graphical user interface (GUI) without relying on external libraries or frameworks. It features a fully functional calculator capable of performing standard arithmetic operations using native Windows window classes (Buttons and Edit controls).

## Features
*   **Native Windows GUI:** Built using `user32` controls, ensuring a very small footprint and fast execution time.
*   **Basic Arithmetic:** Supports Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`).
*   **Floating Point Support:** Calculates and displays decimal numbers accurately.
*   **Controls:** 
    *   `0-9`: Digit inputs.
    *   `C`: Clear the current operation and text box.
    *   `<=`: Backspace (removes the last entered character).
    *   `=`: Calculates the result.

## Prerequisites
To compile this project, you need a C compiler configured for Windows development. Popular options include:
*   **MinGW / GCC** (GNU Compiler Collection)
*   **MSVC** (Microsoft Visual C++ Compiler via Visual Studio)
*   **Clang**
