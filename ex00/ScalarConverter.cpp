#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string &value)
{
    double res;
    res = strtod(value.c_str(), NULL);
    
    //toChar
    char _char;
    _char = static_cast<char>(res);
    if (value == "nan")
        std::cout << "char: impossible" << std::endl;
    else if (isprint(_char))
        std::cout << "char: " << _char << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;//informative message?

    //toInt
    long long _int;
    _int = static_cast<long long>(res);
    if (value == "nan" || _int < INT_MIN || _int > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
    {
        _int = static_cast<int>(res);
        std::cout << "int: " << _int << std::endl;
    }

    //toFloat
    float _float;
    _float = static_cast<float>(res);
    std::cout << "float: " << _float;
    if (_float == static_cast<int>(res))
        std::cout << ".0";
    std::cout << 'f' << std::endl;
        

    //toDouble
    // if (value == "nan")
    //     std::cout << "double: nan" << std::endl;
    if (res == static_cast<int>(res))
        std::cout << "double: " << res << ".0" << std::endl;
    else
        std::cout << "double: " << res << std::endl;
    
    //.0f 붙여줄때 문자열로 바꿔서 확인
    //inf값 확인
}
