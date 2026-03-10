#include <iostream>

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