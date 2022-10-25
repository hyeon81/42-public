/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:03 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/25 21:29:27 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	sign = 1;
	num = 0;
	if (!str)
		ft_exit();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		ft_exit();
	while (ft_isdigit(str[i]) == 1)
	{	
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ft_exit();
	num = num * sign;
	if (num > 2147483647 || num < -2147483648)
		ft_exit();
	return (num);
}
