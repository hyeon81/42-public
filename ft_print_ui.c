#include "ft_printf.h"

void	ft_print_ui(unsigned int n)
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
