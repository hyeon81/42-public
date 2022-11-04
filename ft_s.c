/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:38:54 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/04 16:06:06 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node *a_head)
{
    ft_s(a_head);
	ft_putstr("sa\n");
}

void sb(t_node *b_head)
{
    ft_s(b_head);
	ft_putstr("sb\n");
}

void ss(t_stack *stack)
{
    ft_s(stack->a_head);
    ft_s(stack->b_head);
	ft_putstr("ss\n");
}

void ft_s(t_node *head)
{
	int temp;

	// if (head->next->index == -1)
	// 	return ;
	temp = head->next->next->index;
	head->next->next->index = head->next->index;
	head->next->index = temp;
}
