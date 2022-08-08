#include "ft_printf.h"

void	ft_print_long(unsigned long long n)
{
	char	c;

	if (n >= 0)
	{
		if (n > 9)
		{
			c = n % 10 + '0';
			ft_putnbr(n / 10);
			write (1, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			write (1, &c, 1);
		}
	}
}


int ft_print_ptr(unsigned long long num)
{
    unsigned long long ptr = &num;
    ft_print_long(ptr);
}