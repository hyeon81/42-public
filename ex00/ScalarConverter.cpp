#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "[ScalarConverter] is created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
    std::cout << "[ScalarConverter] Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    std::cout << "[ScalarConverter] Copy assignment operator called" << std::endl;
    if (&obj != this)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "[ScalarConverter] is destroyed" << std::endl;
}