/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:51:33 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/08/10 17:44:00 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, char flag, int *res)
{
	int		c;
	char	*hex;

	if (flag == 'x')
		hex = "0123456789abcdef";
	else if (flag == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 0)
	{
		if (n >= 16)
		{
			c = n % 16;
			ft_print_hex(n / 16, flag, res);
			write (1, &hex[c], 1);
			(*res)++;
		}
		else
		{
			write (1, &hex[n], 1);
			(*res)++;
		}
	}
}
