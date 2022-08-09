#include "ft_printf.h"
#include <unistd.h>

void	ft_print_ui(unsigned int n)
{
	char	c;

	if (n >= 0)
	{
		if (n > 9)
		{
			c = n % 10 + '0';
			ft_print_ui(n / 10);
			write (1, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			write (1, &c, 1);
		}
	}
}

// int main()
// {
// 	ft_print_ui(329243);
// 	return (0);
// }
