#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

// int main()
// {
//     printf("%d: %d\n", ft_isalpha('a'), isalpha('a'));
//     printf("%d: %d\n", ft_isalpha('B'), isalpha('B'));
//     printf("%d: %d\n", ft_isalpha('1'), isalpha('1'));
//     printf("%d: %d\n", ft_isalpha('`'), isalpha('`'));
// }