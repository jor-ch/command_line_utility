#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "includes/utilities.h"
#include <optional>
#include <vector>
#include <unordered_map>

/**
 * @brief Enum class representing different arithmetic operators
 *
 */
enum class Operator
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

/**
 * @brief Performs the arithmetic operation on the given input string
 * @param input The input string taken from user input from function basicCalculatorInterface,
 *  which should be in the format of "number operator number operator number ...", for
 * example, "2 + 3 * 4 - 5 / 6".
 * The function takes in the input string, checks if the input is valid, and
 * performs the arithmetic operations according to the order of operations
 * (Multiplication/Division first, then Addition/Subtraction). The function
 * first checks for multiplication and division, then addition and subtraction.
 * If the input is invalid at any point, it returns std::nullopt.
 * Note that for this calculator, parentheses are not supported, and the
 * operations are performed sequentially from left to right, with multiplication
 * and division having higher precedence than addition and subtraction.
 * @return The result of the operation or std::nullopt if the input is invalid
 */
std::optional<double> performOperation(std::string input)
{
    std::vector<std::string> tokens{};
    std::stringstream ss(input);
    std::string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    if (tokens.size() % 2 == 0)
    {
        std::cout << "invalid statement! remember to leave a whitespace between operators and numbers!" << std::endl;
        return std::nullopt;
    }
    std::vector<double> numbersUsed{};
    std::unordered_map<Operator, std::vector<int>> operatorsUsed{}; // 0 for +, 1 for -, 2 for *, 3 for /, idea of map here is to check which tokens use which operators, and how many times each operator is used.
    for (int i = 0; i < tokens.size(); i = i + 2)
    {
        // before converting the token, we need to see if the token is a combination of
        // number and non-number, for example, 2*3, which is an invalid statement for our
        // calculator since we require a space between numbers and operators
        std::string &numToken = tokens[i];
        size_t startIdx = 0;
        if (numToken[0] == '-')
        {
            startIdx = 1; // if the token starts with a negative sign, we want to ignore that when checking if the rest of the token is a valid number
        }
        bool valid = true;
        int decimalCount = 0;
        for (size_t i = startIdx; i < numToken.length(); i++)
        {
            if (numToken[i] == '.')
            {
                decimalCount++;
                if (decimalCount > 1)
                {
                    valid = false; // since we only allow maximum one decimal point in a number
                    break;
                }
            }
            else if (!std::isdigit(static_cast<unsigned char>(numToken[i])))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            std::cout << "invalid statement! Token number " << i + 1 << " is not a valid number!" << std::endl;
            return std::nullopt;
        }

        double num = stod(tokens[i]);
        numbersUsed.push_back(num);
    }
    for (int i = 1; i < tokens.size(); i = i + 2)
    {
        std::string op = tokens[i];
        if (op == "+")
        {
            operatorsUsed[Operator::ADD].push_back(i);
        }
        else if (op == "-")
        {
            operatorsUsed[Operator::SUBTRACT].push_back(i);
        }
        else if (op == "*")
        {
            operatorsUsed[Operator::MULTIPLY].push_back(i);
        }
        else if (op == "/")
        {
            operatorsUsed[Operator::DIVIDE].push_back(i);
        }
        else
        {
            std::cout << "invalid statement! Token number" << i + 1 << " is not a valid operator!" << std::endl;
            return std::nullopt;
        }
    }

    // plan here is to deal with all the multiplication and division first, then modify numbersUsed such that after
    // multiplication and division, second number is the result, first number is 0 (since the operators happen sequentially), since multiplication and division
    // are higher precedence than addition and subtraction, we can just add and subtract the numbers in numbersUsed to get the final result
    for (int i : operatorsUsed[Operator::MULTIPLY])
    {
        double result = numbersUsed[i / 2] * numbersUsed[i / 2 + 1];
        numbersUsed[i / 2] = 0;
        numbersUsed[i / 2 + 1] = result;
    }
    for (int i : operatorsUsed[Operator::DIVIDE])
    {
        if (numbersUsed[i / 2 + 1] == 0)
        {
            std::cout << "invalid statement! division by zero detected!" << std::endl;
            return std::nullopt;
        }
        double result = numbersUsed[i / 2] / numbersUsed[i / 2 + 1];
        numbersUsed[i / 2] = 0;
        numbersUsed[i / 2 + 1] = result;
    }
    // next, with subtraction, we need to multiply the preceding number by -1, and change the operator to addition,
    // since addition and subtraction are of the same precedence, we can just add all the numbers in numbersUsed to get the final result
    for (int i : operatorsUsed[Operator::SUBTRACT])
    {
        numbersUsed[i / 2 + 1] = -numbersUsed[i / 2 + 1];
        operatorsUsed[Operator::ADD].push_back(i);
    }
    // finally, add all the numbers in numbersUsed to get the final result
    double finalResult = 0;
    for (double num : numbersUsed)
    {
        finalResult += num;
    }
    return finalResult;
}

/**
 * @brief Provides the user interface for the basic calculator
 * Shows instructions to the user, takes in the input, calls performOperation to
 * get the result, and displays the result. It also checks if the user wants to
 * continue using the calculator after each operation, and terminates the interface if the
 * user does not want to continue, returning to the main menu.
 */
void basicCalculatorInterface()
{
    std::cout << "Welcome to Basic Calculator! Here, we will perform basic arithmetic operations!" << std::endl;
    std::cout << "type in the statement. This calculator is only limited to +, -, * and / operations." << std::endl;
    std::cout << "Example: 2 + 3 * 4 - 5 / 6" << std::endl;
    std::cout << "Please leave a space between the numbers and operators!" << std::endl;
    std::string input;
    std::optional<double> result = std::nullopt;
    while (true)
    {
        std::cout << "Enter the statement:" << std::endl;
        std::getline(std::cin, input);
        result = performOperation(input);
        if (result.has_value())
        {
            std::cout << "Result is " << result.value() << std::endl;
        }
        else
        {
            std::cout << "Operation failed!" << std::endl;
        }
        if (!checkContinue())
        {
            std::cout << "terminating program!" << std::endl;
            return;
        }
    }
}