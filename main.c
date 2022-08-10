#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int res = 0;
    int a = 10;
    // res = ft_printf("\n%s\n", 0);
    // printf("test res = %d\n", res);
    ft_printf("%s", NULL);
    printf("real res = %d\n", printf("%s", NULL));
	return (0);
}