#include <iostream>
#include "includes/utilities.h"
#include <limits>
#include <sstream>

void basicCalculatorInterface();
void temperatureConverterInterface();
void palindromeCheckerInterface();
void anagramCheckerInterface();

/**
 * @brief Displays the main menu options
 * @details This function prints the available options for the utility program.
 */
void displayMenu()
{
    std::cout << "===== UTILITY PROGRAM MENU =====" << std::endl;
    std::cout << "1. Basic Calculator" << std::endl;
    std::cout << "2. Temperature converter" << std::endl;
    std::cout << "3. Palindrome checker" << std::endl;
    std::cout << "4. Anagram checker" << std::endl;
    std::cout << "5. EXIT" << std::endl;
}

/**
 * @brief Gets the user's choice from the menu
 * @details This function prompts the user to enter a choice and validates it. It keeps
 * prompting the user until a valid choice (1-5) is entered. If the input is not a number
 * or is out of range, it displays an error message and prompts again.
 * @return The valid choice entered by the user
 */
int getChoice()
{
    std::string input;
    int choice;
    while (true)
    {

        std::cout << "Enter your choice (1-5):" << std::endl;
        std::getline(std::cin, input);
        try
        {
            choice = stoi(input);
        }
        catch (...)
        {
            std::cout << "Invalid choice given!" << std::endl;
            continue;
        }
        if (choice < 1 || choice > 5)
        {
            std::cout << "number input invalid!" << std::endl;
            continue;
        }
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
    }
}
int main()
{
    std::cout << "Welcome to utility menu! here are the options:" << std::endl;
    while (true)
    {
        displayMenu();
        int userChoice = getChoice();

        switch (userChoice)
        {
        case 1:
            basicCalculatorInterface();
            break;
        case 2:
            temperatureConverterInterface();
            break;
        case 3:
            palindromeCheckerInterface();
            break;
        case 4:
            anagramCheckerInterface();
            break;
        case 5:
            std::cout << "terminating program!" << std::endl;
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}