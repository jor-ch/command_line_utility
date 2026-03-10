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
void basicCalculatorInterface()
{
    std::cout << "Welcome to Basic Calculator! Here, we will perform basic arithmetic operations!" << std::endl;
    std::cout << "type in the statement. This calculator is only limited to +, -, * and / operations." << std::endl;
    std::cout << "Example: 2 + 3 * 4 - 5 / 6" << std::endl;
    std::cout << "Please leave a space between the numbers and operators!" << std::endl;
    std::string input;
    std::optional<double> result = std::nullopt;
}