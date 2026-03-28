# Command Line Utility

## Overview
This project is a C++ command-line utility program that provides multiple small tools in a single application. It allows users to select different functionalities interactively.

This project was developed as one of the capstone projects for Microsoft’s Introduction to    C++ course on Coursera, showcasing the practical application of core C++ concepts.

The program demonstrates:

Modular programming
Input validation
String processing
Basic algorithm implementation

## Features
The utility program currently supports the following tools:

### Basic Calculator
 - Performs arithmetic operators: addition, subtraction, multiplication and division. 
 - Supports operator precedence, such that multiplication and division are done before addition and subtraction. 
 - Accepts expressions with space-separated tokens.
 Example input: 2 + 3 - 4 * 5 / 6

 Note:
 - parenthesis is not supported yet.
 - spaces between numbers and operators are required.
 - Handles invalid input and division by zero. 

 ### Temperature Converter
 - Converts temperature between Celsius to Farenheit, and vice versa.

### Palindrome Checker
- Checks whether a given string is a palindrome.
- Case-insensitive, and includes special characters as well.

### Anagram Checker
- Checks whether two strings are anagrams.
- Case-insensitive, and ignores non-alphanumeric characters.

## Project Structure
COMMAND_LINE_UTILITY/

│
├── includes/

│   ├── utilities.h

│   └── utilities.cpp

│

├── main.cpp

├── basic_calculator.cpp

├── temperature_converter.cpp

├── palindrome_checker.cpp

├── anagram_checker.cpp

│

├── CMakeLists.txt

└── README.md

## How it works
1. Program starts in main.cpp
2. Menu displays:
    1. Basic Calculator
    2. Temperature converter
    3. Palindrome checker
    4. Anagram checker
    5. EXIT
3. User input is validated using getChoice()
4. Based on the selection, the corresponding interface function is called:
    - basicCalculatorInterface()
    - temperatureConverterInterface()
    - palindromeCheckerInterface()
    - anagramCheckerInterface()

## Requirements
- C++17 or later.
- CMake for building.

## Future Improvements
- Support parenthesis in basic calculator.
- Add automated tests.



