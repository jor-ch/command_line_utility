#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <limits>
#include "includes/utilities.h"
bool checkPalindrome(const std::string &str)
{
    int strLen = str.length();
    // here, we use two pointers to compare the characters of the string, ignoring case
    int left_idx = 0, right_idx = strLen - 1;
    while (left_idx < right_idx)
    {
        if (std::tolower(str[left_idx]) != std::tolower(str[right_idx]))
            return false;
        left_idx++;
        right_idx--;
    }
    return true;
}

void palindromeCheckerInterface()
{
    std::cout << "Welcome to Palindrome checker! Here, we will check if a string is a Palindrome!" << std::endl;
    std::cout << "This checker is case-insensitive and you can include special characters!" << std::endl;
    std::string inputString;
    bool isPalindrome;
    while (true)
    {
        inputString.clear();
        isPalindrome = false;
        std::cout << "enter a string" << std::endl;
        std::getline(std::cin, inputString);
        std::cout << "string is " << inputString << std::endl;
        isPalindrome = checkPalindrome(inputString);
        std::cout << "The string is " << (isPalindrome ? "" : "NOT ") << "a palindrome!" << std::endl;
        if (!checkContinue())
            return;
    }
}