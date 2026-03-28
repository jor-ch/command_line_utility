#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <limits>
#include "includes/utilities.h"

/**
 * @brief Checks if two strings are anagrams of each other
 * @details The function first counts the frequency of each alphanumeric character in the
 * first string, ignoring case and non-alphanumeric characters. Then it checks
 * if the second string has the same characters with the same frequency. If any
 * character in the second string has a different frequency than in the first string,
 * or if there are characters in the second string that are not in the first string,
 * then the function returns false. Finally, it also checks if the total number of
 * alphanumeric characters in both strings are the same, since if they are different,
 * then they cannot be anagrams.
 * @param s1 First string to compare
 * @param s2 Second string to compare
 * @return true if the strings are anagrams, false otherwise
 */
bool checkAnagram(std::string &s1, std::string &s2)
{
    std::unordered_map<char, int> s1CharFreq{}; // this checks what characters are in s1, and the frequency of each character used
    size_t s1Len = 0, s2Len = 0;
    for (char c : s1)
    {
        if (std::isalnum(static_cast<unsigned char>(c)))
        {
            c = std::tolower(static_cast<unsigned char>(c));
            s1CharFreq[c]++;
            s1Len++;
        }
    }
    // check if s2 has the same char and freq
    for (char c : s2)
    {
        if (std::isalnum(static_cast<unsigned char>(c)))
        {
            c = std::tolower(static_cast<unsigned char>(c));
            s2Len++;
            if (s1CharFreq.count(c))
            {
                s1CharFreq[c]--;
                if (s1CharFreq[c] < 0)
                    return false; // used more of the char than s1, so not anagram
            }
            else
            {
                return false; // s2 has a char that is not in s1
            }
        }
        else
        {
            continue; // ignore non-alphanumeric characters
        }
    }
    if (s1Len != s2Len)
        return false; // if the length of the two strings are different, then they cannot be anagrams
    return true;
}

/**
 * @brief Provides the user interface for the anagram checker
 * @details This function shows instructions to the user, takes in the input twice for the
 * two strings to compare, calls checkAnagram to check if the two strings are anagrams,
 * and displays the result. It also checks if the user wants to continue using the
 * anagram checker after each operation, and terminates the interface if the
 * user does not want to continue, returning to the main menu.
 */
void anagramCheckerInterface()
{
    std::cout << "Welcome to Anagram checker! Here, we will check if two strings are anagrams!" << std::endl;
    std::cout << "Note: Any non-alphanumeric characters will be ignored" << std::endl;
    std::string string1, string2;
    bool isAnagram;
    while (true)
    {
        string1.clear();
        string2.clear();
        isAnagram = false;
        std::cout << "enter first string" << std::endl;
        std::getline(std::cin, string1);
        std::cout << "string 1 is " << string1 << std::endl;
        std::cout << "enter second string" << std::endl;
        std::getline(std::cin, string2);
        std::cout << "string 2 is " << string2 << std::endl;
        isAnagram = checkAnagram(string1, string2);
        std::cout << "Both strings given are " << (isAnagram ? "" : "NOT ") << "anagrams!" << std::endl;
        if (!checkContinue())
            return;
    }
}