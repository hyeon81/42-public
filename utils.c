/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:57:31 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 19:51:20 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int i, int sign)
{
	long long	num;

	num = 0;
	if (!str)
		error_exit();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		error_exit();
	while (ft_isdigit(str[i]) == 1)
	{	
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		error_exit();
	num = num * sign;
	if (num > 2147483647 || num < -2147483648)
		error_exit();
	return (num);
}

t_node	*ft_init_lstnew(int data, int index)
{
	t_node	*curr;

	curr = (t_node *)malloc(sizeof(t_node));
	if (!curr)
		error_exit();
	curr -> next = NULL;
	curr -> prev = NULL;
	curr -> index = index;
	curr -> data = data;
	return (curr);
}

t_node	*ft_lstnew(int index)
{
	t_node	*curr;

	curr = (t_node *)malloc(sizeof(t_node));
	if (!curr)
		error_exit();
	curr -> next = NULL;
	curr -> prev = NULL;
	curr -> index = index;
	return (curr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
}
