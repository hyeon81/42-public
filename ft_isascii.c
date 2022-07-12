#include <stdio.h>
#include <ctype.h>

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return 1;
    return 0;
}

// int main()
// {
//     printf("%d: %d\n", ft_isascii('a'), isascii('a'));
//     printf("%d: %d\n", ft_isascii(-1), isascii(-1));
//     printf("%d: %d\n", ft_isascii(256), isascii(256));
//     printf("%d: %d\n", ft_isascii('1'), isascii('1'));
//     printf("%d: %d\n", ft_isascii('`'), isascii('`'));
// }