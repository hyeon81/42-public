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

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n >= 0)
	{
		if (n > 9)
		{
			c = n % 10 + '0';
			ft_putnbr_fd(n / 10, fd);
			write (fd, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			write (fd, &c, 1);
		}
	}
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
}
