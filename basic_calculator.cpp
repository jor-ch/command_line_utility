#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "includes/utilities.h"
#include <optional>
#include <vector>
#include <unordered_map>

enum class Operator
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

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
        try
        {
            double num = stod(tokens[i]);
            numbersUsed.push_back(num);
        }
        catch (...)
        {
            std::cout << "invalid statement! Token number " << i + 1 << " is not a valid number!" << std::endl;
            return std::nullopt;
        }
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
    // multiplication and division, second number is the result, first number is 0, since multiplication and division
    // are higher precedence than addition and subtraction, we can just add and subtract the numbers in numbersUsed to get the final result
    for (int i : operatorsUsed[Operator::MULTIPLY])
    {
        double result = numbersUsed[i / 2] * numbersUsed[i / 2 + 1];
        numbersUsed[i / 2] = 0;
        numbersUsed[i / 2 + 1] = result;
    }
    for (int i : operatorsUsed[Operator::DIVIDE])
    {
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
void basicCalculatorInterface()
{
    std::cout << "Welcome to Basic Calculator! Here, we will perform basic arithmetic operations!" << std::endl;
    std::cout << "type in the statement. This calculator is only limited to +, -, * and / operations." << std::endl;
    std::cout << "Example: 2 + 3 * 4 - 5 / 6" << std::endl;
    std::cout << "Please leave a space between the numbers and operators!" << std::endl;
    std::string input;
    std::optional<double> result = std::nullopt;
}