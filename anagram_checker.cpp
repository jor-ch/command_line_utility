#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <limits>

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

bool checkContinue()
{
    std::string input;
    std::cout << "continue? y/n" << std::endl;
    while (true)
    {
        std::getline(std::cin, input);
        if (input != "y" && input != "n")
        {
            std::cout << "invalid option! put either y or n!" << std::endl;
        }
        else if (input == "y")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

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
        std::cout << "Both strings given are " << (isAnagram ? " " : "NOT ") << "anagrams!" << std::endl;
        if (!checkContinue())
            return;
    }
}