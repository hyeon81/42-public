#include <stdio.h>

int main(int ac, char **av)
{
    if (ac < 6)
        return (0);
    int i = ac - 1;
    while (i > 0)
    {
        printf("%s ", av[i]);
        i--;
    }
    return (0);
}