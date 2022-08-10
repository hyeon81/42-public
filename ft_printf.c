/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:53:07 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/08/10 19:24:17 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flag(va_list args, const char c)
{
	int	res;

	res = 0;
	if (c == 'c')
		ft_putchar(va_arg(args, int), &res);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), &res);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, void *), &res);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &res);
	else if (c == 'u')
		ft_print_ui(va_arg(args, unsigned int), &res);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(args, unsigned int), c, &res);
	else if (c == '%')
	{
		write(1, "%", 1);
		res += 1;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			ret += ft_check_flag(args, str[i]);
		}
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
