/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:43:52 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/16 11:53:14 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_and_change_value(t_stack *a, t_stack *b, int *i, int *size)
{
	pb(a, b, 1);
	if (*i >= 0)
		(*i)++;
	if (*size >= 0)
		(*size)--;
}

void	a_to_b(t_stack *a, t_stack *b, int i, int chunk)
{
	int	top;
	int	size;
	int	res;

	size = a->size - 1;
	res = check_descending(a);
	while (i < a->size)
	{
		top = a->head->next->index;
		if (top <= i)
			pb_and_change_value(a, b, &i, &size);
		else if (top > i && top <= chunk + i)
		{
			pb_and_change_value(a, b, &i, &size);
			rb(b, 1);
		}
		else if (top > (i + chunk))
		{
			if (res == 1)
				rra(a, 1);
			else
				ra(a, 1);
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
		rb(b, 1);
		i--;
	}
	if (i >= max / 2)
	{
		i = max - i + 1;
		while (i > 0)
		{
			rrb(b, 1);
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
		pa(a, b, 1);
		max--;
	}
}
