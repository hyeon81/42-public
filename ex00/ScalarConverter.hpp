#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#ifndef SCALACONVERTER
#define SCALACONVERTER

#include <iostream>
#include <string>
class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();
};

#endif
