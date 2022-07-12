#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

// int main()
// {
//     printf("%d: %d\n", ft_isdigit('a'), isdigit('a'));
//     printf("%d: %d\n", ft_isdigit(-1), isdigit(-1));
//     printf("%d: %d\n", ft_isdigit('6'), isdigit('6'));
//     printf("%d: %d\n", ft_isdigit('1'), isdigit('1'));
//     printf("%d: %d\n", ft_isdigit('`'), isdigit('`'));
// }