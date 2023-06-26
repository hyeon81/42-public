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

void ScalarConverter::convert(std::string &value)
{
    double res;
    res = strtod(value.c_str(), NULL);
    
    //toChar
    char _char;
    _char = static_cast<char>(res);
    if (value == "nan")
        std::cout << "char: " << "impossible" << std::endl;
    else if (isprint(_char))
        std::cout << "char: " << _char << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;//informative message?

    //toInt
    int _int;
    _int = static_cast<int>(res);
    if (value == "nan")
        std::cout << "char: " << "impossible" << std::endl;
    else
        std::cout << "char: " << _int << std::endl;

    //toFloat
    float _float;
    _float = static_cast<float>(res);
    if (value == "nan")
        std::cout << "float: " << "nanf" << std::endl;
    else if (_float == static_cast<int>(res))
        std::cout << "float: " << _float << ".0f" << std::endl;
    else
        std::cout << "float: " << _float << std::endl;

    //toDouble
    if (value == "nan")
        std::cout << "double: nanf" << std::endl;
    else if (res == static_cast<int>(res))
        std::cout << "double: " << res << ".0" << std::endl;
    else
        std::cout << "double: " << res << std::endl;
    
    //.0f 붙여줄때 문자열로 바꿔서 확인
    //inf값 확인
}
