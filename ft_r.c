/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:58:01 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 19:58:01 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int flag)
{
	if (a->head->next == a->tail)
		return ;
	ft_r(a);
	if (flag == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack *b, int flag)
{
	if (b->head->next == b->tail)
		return ;
	ft_r(b);
	if (flag == 1)
		ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b, int flag)
{
	if (a->head->next == a->tail || b->head->next == b->tail)
		return ;
	ra(a);
	rb(b);
	ft_putstr("rr\n");
}

void	ft_r(t_stack *s)
{
	int	temp;

	temp = s->head->next->index;
	remove_node_top(s->head);
	insert_node_bottom(temp, s->tail);
}
