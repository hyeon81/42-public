/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:46:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 19:44:52 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int flag)
{
	if (a->head->next == a->tail)
		return ;
	ft_rr(a);
	if (flag == 1)
		ft_putstr("rra\n");
}

void	rrb(t_stack *b, int flag)
{
	if (b->head->next == b->tail)
		return ;
	ft_rr(b);
	if (flag == 1)
		ft_putstr("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, int flag)
{
	if (a->head->next == a->tail || b->head->next == b->tail)
		return ;
	ft_rr(a);
	ft_rr(b);
	if (flag == 1)
		ft_putstr("rrr\n");
}

void	ft_rr(t_stack *s)
{
	int	temp;

	temp = s->tail->prev->index;
	remove_node_bottom(s->tail);
	insert_node_top(temp, s->head);
}
