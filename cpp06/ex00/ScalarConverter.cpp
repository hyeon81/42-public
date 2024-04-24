#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string &value)
{
    double res;
    char _char;
    long long _int;
    float _float;

    char *stopstring;
    res = strtod(value.c_str(), &stopstring);
    
    //if argv is char
    std::string tmp(stopstring);
    if (value.length() == 1 && res == 0 && tmp.length() == 1)
        res = static_cast<double>(value[0]);
    
    //toChar
    _char = static_cast<char>(res);
    if (value == "nan" || res > 255)
        std::cout << "char: impossible" << std::endl;
    else if (res > 31 && res < 127)
        std::cout << "char: " << _char << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    //toInt
    _int = static_cast<long long>(res);
    if (value == "nan" || _int < INT_MIN || _int > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
    {
        _int = static_cast<int>(res);
        std::cout << "int: " << _int << std::endl;
    }

    //toFloat
    _float = static_cast<float>(res);
    std::cout << "float: " << _float;
    if (_float == static_cast<int>(res))
        std::cout << ".0";
    std::cout << 'f' << std::endl;

    if (res == static_cast<int>(res))
        std::cout << "double: " << res << ".0" << std::endl;
    else
        std::cout << "double: " << res << std::endl;    
}
