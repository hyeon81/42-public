#include "iter.hpp"

int main(void)
{
    int num[5] = { 1, 2, 3, 4, 5 };
    char str[5] = {'a', 'b', 'c', 'd', 'e'};

    iter(num, 5, print);
    iter(str, 5, print);

    return (0);
}