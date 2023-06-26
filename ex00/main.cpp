#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "argument is only one" << std::endl;
        return (0);
    }
    std::string value(av[1]);
    ScalarConverter::convert(value);
    //static 함수가 있으면 그게 static 클래스인가?
    /*char: Non displayable
    int: 0
    float: 0.0f
    double: 0.0*/
}
