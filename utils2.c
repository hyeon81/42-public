/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:17:42 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/16 11:53:22 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_exit(char *s)
{
	if (s != NULL)
		ft_putstr(s);
	exit(0);
}

int	ft_double_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	is_descending(t_stack *a, t_node *curr)
{
	int		i;
	int		val;
	double	down;

	i = 0;
	down = 0;
	val = curr->index;
	curr = curr->next;
	while (i < 10 && curr != a->tail)
	{
		if (val > curr->index)
			down++;
		val = curr->index;
		curr = curr->next;
		i++;
	}
	if (down / 10 > 0.85)
		return (1);
	return (0);
}

int	check_descending(t_stack *a)
{
	t_node	*curr;
	double	cnt;

	cnt = 0;
	curr = a->head->next;
	while (curr != a->tail)
	{
		cnt += is_descending(a, curr);
		curr = curr->next;
	}
	if ((cnt / (a->size / 10)) > 0.85)
		return (1);
	return (0);
}
