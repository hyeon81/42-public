#include <ctype.h>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
        return (0);
    }
    int i = 1;
    int j;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            std::cout << static_cast<char>(toupper(av[i][i]));
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    
    return (0);
}