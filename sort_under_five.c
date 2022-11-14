/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:43:06 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 21:41:37 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_list(t_stack *a)
{
	int	one;
	int	two;
	int	three;

	one = a->head->next->index;
	two = a->head->next->next->index;
	three = a->tail->prev->index;
	if ((one > two) && (two > three) && (one > three))
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if ((one > two) && (three > two) && (one > three))// 3 1 2
		ra(a, 1);
	else if ((one > two) && (two < three) && (one < three))// 2 1 3
		sa(a, 1);
	else if ((one < two) && (two > three) && (one > three))// 2 3 1
		rra(a, 1);
	else if ((one < two) && (two > three) && (one < three))// 1 3 2
	{
		sa(a, 1);
		ra(a, 1);
	}
}

void	sort_four_list(t_stack *a, t_stack *b)
{
	t_node	*curr;
	int		min;
	int		top;

	min = a->head->next->index;
	curr = a->head->next;
	while (curr != a->tail)
	{
		if (min > curr->index)
			min = curr->index;
		curr = curr -> next;
	}
	while (1)
	{
		top = a->head->next->index;
		if (top == min)
		{
			pb(a, b, 1);
			break ;
		}
		ra(a, 1);
	}
	sort_three_list(a);
	pa(a, b, 1);
}

void	make_min(t_stack *a, t_stack *b, int min, int i)
{
	int		top;

	top = 0;
	while (top != -1)
	{
		top = a->head->next->index;
		if (top == min)
		{
			pb(a, b, 1);
			break ;
		}
		if (i < 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	sort_five_list(t_stack *a, t_stack *b)
{
	int		i;
	int		idx;
	int		min;
	t_node	*curr;

	i = -1;
	idx = 0;
	while (++i < 2)
	{
		curr = a->head->next;
		min = a->head->next->index;
		while (curr != a->tail)
		{
			if (min > curr->index)
			{
				min = curr->index;
				idx++;
			}
			curr = curr->next;
		}
		make_min(a, b, min, idx);
	}
	sort_three_list(a);
	pa(a, b);
	pa(a, b);
}

void	sort_under_five(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->head->next->index > a->head->next->next->index)
			sa(a);
	}
	else if (a->size == 3)
		sort_three_list(a);
	else if (a->size == 4)
		sort_four_list(a, b);
	else if (a->size == 5)
		sort_five_list(a, b);
	exit(0);
}
