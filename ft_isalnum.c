#include "libft.h"

int ft_isalnum(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

// int main()
// {
//     printf("%d: %d\n", ft_isalnum('a'), isalnum('a'));
//     printf("%d: %d\n", ft_isalnum('1'), isalnum('1'));
//     printf("%d: %d\n", ft_isalnum('`'), isalnum('`'));
// }