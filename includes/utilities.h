#pragma once
#include <iostream>

constexpr double CELSIUS_TO_FAHRENHEIT_MULTIPLIER = 9.0 / 5.0;
constexpr double CELSIUS_TO_FAHRENHEIT_CONSTANT = 32.0;

/**
 * @brief Checks if the user wants to continue using the interface after each operation
 * @details This function prompts the user to enter 'y' or 'n' to indicate whether they
 * want to continue using the interface. It keeps prompting the user until a valid
 * input is given ('y' or 'n'). If the user enters 'y', the function returns true,
 * indicating that the user wants to continue. If the user enters 'n', the function returns
 * false, indicating that the user does not want to continue.
 * @return true if the user wants to continue, false otherwise
 */
bool checkContinue();