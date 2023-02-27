#include <ctype.h>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str;
    if (ac == 1)
    {
        //* LOUD AND UNBEARABLE FEEDBACK NOISE *
        return (0);
    }
    int i = 0;
    int j = 0;
    while (j < 5)
    {
       str += (toupper(av[1][i]));
       i++;
    }
    int j = 0;
    std::cout << str << std::endl;
    
    return (0);
}