#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();
        static void convert(std::string &value);
};

#endif
