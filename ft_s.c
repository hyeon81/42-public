/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:38:54 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 19:45:17 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int flag)
{
	if (a->head->next == a->tail)
		return ;
	ft_s(a);
	if (flag == 1)
		ft_putstr("sa\n");
}

void	sb(t_stack *b, int flag)
{
	if (b->head->next == b->tail)
		return ;
	ft_s(b);
	if (flag == 1)
		ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b, int flag)
{
	ft_s(a);
	ft_s(b);
	if (flag == 1)
		ft_putstr("ss\n");
}

void	ft_s(t_stack *s)
{
	int	temp;

	temp = s->head->next->next->index;
	s->head->next->next->index = s->head->next->index;
	s->head->next->index = temp;
}
