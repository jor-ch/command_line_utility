#include <iostream>
#include "includes/utilities.h"
#include <optional>

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
