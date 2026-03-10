#include <iostream>
#include "includes/utilities.h"
#include <optional>
#include <sstream>

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

void temperatureConverterInterface()
{
    std::cout << "Welcome to Temperature Converter! Here, we will convert temperatures between Celsius and Fahrenheit!" << std::endl;
    std::cout << "Note: currently, we only support conversion between Celsius and Fahrenheit!" << std::endl;
    std::cout << "Format of input is temperature value and C/F, to indicate if temperature is in Celsius or Farenheit" << std::endl;
    std::cout << "Example: 32.5 C  (this is to convert 32.5 degrees celsius to farenheit)" << std::endl;
    std::cout << "Please enter the temperature value, followed by letter:" << std::endl;
    std::string input;
    std::optional<double> result = std::nullopt;
}
