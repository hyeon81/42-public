#include <ctype.h>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str;
    
    if (ac == 1)
    {
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
        return (0);
    }
    int i = 0;
    int j = 0;
    while (i < ac)
    {
       str += (toupper(av[1][i]));
       i++;
    }
    int j = 0;
    std::cout << str << std::endl;
    
    return (0);
}