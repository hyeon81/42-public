/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:38:59 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/16 12:28:12 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
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
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
}
