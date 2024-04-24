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
}
