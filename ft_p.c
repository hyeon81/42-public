/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:43:25 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 19:58:42 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, int flag)//b to a
{
	if (b->head->next == b->tail)
		return ;
	ft_p(b, a);
	if (flag == 1)
		ft_putstr("pa\n");
}

void	pb(t_stack *a, t_stack *b, int flag)//a to b
{
	if (a->head->next == a->tail)
		return ;
	ft_p(a, b);
	if (flag == 1)
		ft_putstr("pb\n");
}

void	ft_p(t_stack *pop, t_stack *push, int flag)
{
	int	temp;

	temp = pop->head->next->index;
	remove_node_top(pop->head);
	insert_node_top(temp, push->head);
}
