#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <limits>
#include "includes/utilities.h"

void palindromeCheckerInterface()
{
    std::cout << "Welcome to Palindrome checker! Here, we will check if two strings are Palindrome!" << std::endl;
    std::string string1, string2;
    bool isPalindrome;
    while (true)
    {
        string1.clear();
        string2.clear();
        isPalindrome = false;
        std::cout << "enter first string" << std::endl;
        std::getline(std::cin, string1);
        std::cout << "string 1 is " << string1 << std::endl;
        std::cout << "enter second string" << std::endl;
        std::getline(std::cin, string2);
        std::cout << "string 2 is " << string2 << std::endl;
        // isPalindrome = checkPalindrome(string1, string2);
        std::cout << "Both strings given are " << (isPalindrome ? "" : "NOT ") << "palindromes!" << std::endl;
        if (!checkContinue())
            return;
    }
}