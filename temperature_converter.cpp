#include <iostream>
#include "includes/utilities.h"
#include <optional>
#include <sstream>

/**
 * @brief Performs the temperature conversion based on the input string
 * @param input The input string, taken from user input from function
 * temperatureConverterInterface, which should be in the format of
 * "temperatureValue unit", where unit is either C or F, indicating if the
 * temperature value is in Celsius or Fahrenheit. For example,
 * "32.5 C" means 32.5 degrees Celsius, and we want to convert that to Fahrenheit.
 * If the input is invalid, such as missing the unit, or having too many tokens,
 * or having an invalid unit, the function will return std::nullopt.
 * @return The converted temperature or std::nullopt if the input is invalid
 */
std::optional<double> performConversion(std::string input)
{
    std::stringstream ss(input);
    double inputValue;
    char inputUnit;
    std::string extraToken; // use this to check if there are too many tokens in the input
    if (!(ss >> inputValue >> inputUnit))
    {
        std::cout << "invalid input! remember to put a space between the temperature value and unit!" << std::endl;
        return std::nullopt;
    }
    if (ss >> extraToken)
    {
        std::cout << "invalid input! too many tokens!" << std::endl;
        return std::nullopt;
    }
    if (inputUnit == 'C' || inputUnit == 'c')
    {
        // convert to fahrenheit
        return inputValue * CELSIUS_TO_FAHRENHEIT_MULTIPLIER + CELSIUS_TO_FAHRENHEIT_CONSTANT;
    }
    else if (inputUnit == 'F' || inputUnit == 'f')
    {
        // convert to celsius
        return (inputValue - CELSIUS_TO_FAHRENHEIT_CONSTANT) / CELSIUS_TO_FAHRENHEIT_MULTIPLIER;
    }
    else
    {
        std::cout << "invalid input! temperature unit must be either C or F!" << std::endl;
        return std::nullopt;
    }
}

/**
 * @brief Provides the user interface for the temperature converter
 * This function shows instructions to the user, takes in the input, calls
 * performConversion to get the result, and displays the result. It also checks
 * if the user wants to continue using the converter after each operation. If the user
 * does not want to continue, the function terminates the interface and returns to the main menu.
 * Note that this function currently only supports conversion between Celsius and
 * Fahrenheit, and the input format must be "temperatureValue unit", where unit is either
 * C or F, indicating if the temperature value is in Celsius or Fahrenheit.
 */
void temperatureConverterInterface()
{
    std::cout << "Welcome to Temperature Converter! Here, we will convert temperatures between Celsius and Fahrenheit!" << std::endl;
    std::cout << "Note: currently, we only support conversion between Celsius and Fahrenheit!" << std::endl;
    std::cout << "Format of input is temperature value and C/F, to indicate if temperature is in Celsius or Farenheit" << std::endl;
    std::cout << "Example: 32.5 C  (this is to convert 32.5 degrees celsius to farenheit)" << std::endl;
    std::string input;
    std::optional<double> result = std::nullopt;
    while (true)
    {
        std::cout << "Please enter the temperature value, followed by a space then letter:" << std::endl;
        std::getline(std::cin, input);
        result = performConversion(input);
        if (result.has_value())
        {
            std::cout << "Result is " << result.value() << std::endl;
        }
        else
        {
            std::cout << "Conversion failed!" << std::endl;
        }
        if (!checkContinue())
        {
            std::cout << "terminating program!" << std::endl;
            return;
        }
    }
}
