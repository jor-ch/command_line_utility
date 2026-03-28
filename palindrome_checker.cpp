#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <limits>
#include "includes/utilities.h"

/**
 * @brief Checks if a string is a palindrome
 * @details The function uses two pointers, one starting from the beginning of the string and
 * the other starting from the end of the string. It compares the characters at the two
 * pointers, ignoring case. If the characters are not the same, it returns false, indicating
 * that the string is not a palindrome. If the characters are the same, it moves the left
 * pointer to the right and the right pointer to the left, and continues comparing until the
 * pointers meet or cross each other. If all characters match, it returns true, indicating
 * that the string is a palindrome.
 * @param str The input string to check for palindrome
 * @return true if the string is a palindrome, false otherwise
 */
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

/**
 * @brief Provides a simple interface for the user to check if a string is a palindrome
 * @details This function prompts the user to enter a string and then checks if it is a
 * palindrome using the checkPalindrome function. It displays the result to the user and
 * then asks if they want to continue checking for palindromes. If the user chooses to
 * continue, it repeats the process; otherwise, it terminates and returns to the main menu.
 * Note that this interface is case-insensitive.
 */
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