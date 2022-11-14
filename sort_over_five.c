/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:43:52 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 21:21:09 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_descending(t_stack *a, int idx)
{
	t_node	*curr;
	int		down;
	int		i;
	int		val;
	double	down_res;
	int		j;

	curr = a->head->next;
	while (idx != 0 && curr != a->tail)
	{
		curr = curr->next;
		idx--;
	}
	down_res = 0;
	j = 0;
	i = 0;
	down = 0;
	val = curr->index;
	curr = curr->next;
	while (i < 10 && curr != a->tail)
	{
		if (val > curr->index)
			down++;
		i++;
		val = curr->index;
		curr = curr->next;
	}
	j++;
	if ((down / 10) > 0.5)
		return (1);
	return (0);
}

void	a_to_b(t_stack *a, t_stack *b, int i, int chunk)
{
	int	top;
	int	size;
	int	res;

	size = a->size - 1;
	if (i % 10 == 0)
		res = check_descending(a, i);
	while (i < a->size)
	{
		top = a->head->next->index;
		if (top <= i)
		{
			pb(a, b);
			size--;
			i++;
		}
		else if (top > i && top <= chunk + i)
		{
			pb(a, b);
			rb(b);
			size--;
			i++;
		}
		else if (top > (i + chunk))
		{
			if (res == 1)
				rra(a);
			else
				ra(a);
			// if (i < size / 2)
			// 	rra(a);
			// else
			// 	ra(a);
		}
	}
}

void	make_b(t_stack *b, int max, int i)
{
	t_node	*curr;

	curr = b->head->next;
	while (i <= max)
	{
		if (curr->index == max)
			break ;
		i++;
		curr = curr -> next;
	}
	while (i < max / 2 && i > 0)
	{
		rb(b);
		i--;
	}
	if (i >= max / 2)
	{
		i = max - i + 1;
		while (i > 0)
		{
			rrb(b);
			i--;
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	max;

	max = a->size - 1;
	while (max >= 0)
	{
		make_b(b, max, 0);
		pa(a, b);
		max--;
	}
}

void	sort_over_five(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = 0.000000053 * (a->size * a->size) + 0.03 * a->size + 14.5;
	if (a->size == 500)
		chunk = 29;
	if (a->size == 100)
		chunk = 15;
	a_to_b(a, b, 0, chunk);
	b_to_a(a, b);
}
