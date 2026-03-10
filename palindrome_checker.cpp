#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <limits>
#include "includes/utilities.h"
bool checkPalindrome(const std::string &str1, const std::string &str2)
{
    int str1Len = str1.length();
    int str2Len = str2.length();
    if (str1Len != str2Len)
        return false; // since the lengths are different, they cannot be palindromes of each other
    // here, we use two pointers to compare the characters of the strings, ignoring case
    int left_idx = 0, right_idx = str2Len - 1;
    while (left_idx < str1Len && right_idx >= 0)
    {
        if (std::tolower(str1[left_idx]) != std::tolower(str2[right_idx]))
            return false;
        left_idx++;
        right_idx--;
    }
    return true;
}

void palindromeCheckerInterface()
{
    std::cout << "Welcome to Palindrome checker! Here, we will check if two strings are Palindrome!" << std::endl;
    std::cout << "This checker is case-insensitive and you can include special characters!" << std::endl;
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
        isPalindrome = checkPalindrome(string1, string2);
        std::cout << "Both strings given are " << (isPalindrome ? "" : "NOT ") << "palindromes!" << std::endl;
        if (!checkContinue())
            return;
    }
}