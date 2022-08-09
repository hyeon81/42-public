#include "ft_printf.h"
#include <unistd.h>

void	ft_print_hex_ptr(unsigned int n)
{
	char	c;
    char    *hex;

    hex = "0123456789abcdef";
	if (n >= 0)
	{
		if (n > 16)
		{
			c = n % 16;
			ft_print_hex_ptr(n / 16);
			write (1, &hex[c], 1);
		}
		else
		{
			c = n % 16;
			write (1, &hex[c], 1);
		}
	}
}


int ft_print_ptr(void *ptr)
{
	unsigned long long ptr2;
    ptr2 = (unsigned long long)ptr;
    ft_print_hex_ptr(ptr2);
}

int main()
{
	char *arr = "123";
	ft_print_ptr(&arr);
	return (0);
}
