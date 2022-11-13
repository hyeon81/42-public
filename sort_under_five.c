/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:43:06 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/13 20:43:32 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_list(t_stack *stack)
{
	int index0;
	int index1;
	int index2;

	index0 = stack->a_head->next->index;
	index1 = stack->a_head->next->next->index;
	index2 = stack->a_tail->prev->index;

	if ((index0 > index1) && (index1 > index2) && (index0 > index2))
	{
		sa(stack->a_head);
		rra(stack);
	}
	//3 1 2
	else if ((index0 > index1) && (index2 > index1) && (index0 > index2))
		ra(stack);
	//2 1 3
	else if ((index0 > index1) && (index1 < index2) && (index0 < index2))
		sa(stack->a_head);
	//2 3 1
	else if ((index0 < index1) && (index1 > index2) && (index0 > index2))
		rra(stack);
	//1 3 2
	else if ((index0 < index1) && (index1 > index2) && (index0 < index2))
	{
		sa(stack->a_head);
		ra(stack);
	}
	
}

void sort_four_list(t_stack *stack)
{
	t_node *curr;
	int min;
	int top;
	
	min = stack->a_head->next->index;
	curr = stack->a_head->next;
	while (curr->index != -1)
	{
		if (min > curr->index)
			min = curr->index;
		curr = curr -> next;
	}
	while (1)
	{
		top = stack->a_head->next->index;
		if (top == min)
		{
			pb(stack);
			break;
		}
		ra(stack);
	}
	sort_three_list(stack);
	pa(stack);
}

void sort_five_list(t_stack *stack)
{
	t_node *curr;
	int min;
	int top;
	int i = 0;
	int j;
	while (i < 2)
	{
		j = 0;
		min = stack->a_head->next->index;
		curr = stack->a_head->next;
		while (curr->index != -1)
		{
			if (min > curr->index)
			{
				min = curr->index;
				j++;
			}
			curr = curr -> next;
		}
		while (1)
		{
			top = stack->a_head->next->index;
			if (top == min)
			{
				pb(stack);
				break;
			}
			if (j < 2)
				ra(stack);
			else
				rra(stack);
		}
		i++;
	}
	sort_three_list(stack);
	pa(stack);
	pa(stack);
}

void sort_under_five(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->a_head->index > stack->a_head->next->index)
			sa(stack->a_head);
	}
	else if (stack->size == 3)
		sort_three_list(&stack);
	else if (stack->size == 4)
		sort_four_list(&stack);
	else if (stack->size == 5)
		sort_five_list(&stack);
	exit(0);
}

