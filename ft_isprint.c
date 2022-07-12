#include "libft.h"

int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return 1;
    return 0;
}

// int main()
// {
//     printf("%d: %d\n", ft_isprint('a'), isprint('a'));
//     printf("%d: %d\n", ft_isprint(-1), isprint(-1));
//     printf("%d: %d\n", ft_isprint('6'), isprint('6'));
//     printf("%d: %d\n", ft_isprint(257), isprint(257));
//     printf("%d: %d\n", ft_isprint('`'), isprint('`'));
// }