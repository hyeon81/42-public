#include "ft_printf.h"

#include <stdarg.h> // va_list, va_start, va_arg, va_end가 정의된 헤더 파일
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void ft_check_flag(va_list args, const char c)
{
	int res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(args, int));
	else if (c == 's')
		res += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		res += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		res += ft_print_ui(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		res += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		res += ft_print_percent();
	retrun (res);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int i = 0;
	int res = 0;

	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			ft_check_flag(args, str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}
int main()
{
	
	return (0);
}