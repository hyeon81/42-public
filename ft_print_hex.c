#include "ft_printf.h"

void	ft_print_hex(unsigned int n, char flag)
{
	char	c;
    char    *hex;

    if (flag == 'x')
        hex = "0123456789abcdef";
    else if (flag == 'X')
        hex = "0123456789ABCDEF";
	if (n >= 0)
	{
		if (n > 16)
		{
			c = n % 16;
			ft_putnbr(n / 16);
			write (1, &hex[c], 1);
		}
		else
		{
			c = n % 16;
			write (1, &hex[c], 1);
		}
	}
}
