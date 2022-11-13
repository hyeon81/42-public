/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:43:52 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/13 20:44:03 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a_to_b(t_stack *stack, int i, int chunk)
{
	int top;
	int length;

	length = stack->size;
	while (i < length)
	{
		top = stack->a_head->next->index;
		if (top <= i)
		{
			pb(stack);
			i++;
		}
		else if (top > i && top <= chunk + i)
		{
			pb(stack);
			i++;
			rb(stack);
		}
		else if (top > (i + chunk))
		{
			if (i < length / 2)
				rra(stack);
			else
				ra(stack);
		}
	}
}

int	sort_b(t_stack *stack, int max)
{
	t_node *curr;
	int	i;
	int sub = 0;

	i = 0;
	int size = max + 1;
	curr = stack->b_head->next;
	if (curr->index == max)
		return (0);
	while (i < size)
	{
		if (curr->index == max)
			break;
		i++;
		curr = curr -> next;
	}
	curr = stack->b_head->next;

	if (i < size / 2) //중간값보다 작음
	{
		while (i > 0)
		{
			rb(stack);
			i--;
		}
	}

	else if (i >= size / 2)//중간값보다 큼
	{
		i = size - i;
		sub = size - sub;
		while (i > 0)
		{
	
			rrb(stack);
			i--;
		}
	}
	return (sub);
	return (0);
}

void	b_to_a(t_stack *stack)
{
	int	max;
	int sub;

	max = stack->size - 1;
	while (max >= 0)
	{
		sub = sort_b(stack, max);
		pa(stack);
		if (sub == -1)
		{
			max--;
			rra(stack);
		}
		max--;
	}
}