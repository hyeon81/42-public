/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:32 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/13 21:40:56 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_lstnew(int data, int index)
{
	t_node	*curr;

	curr = (t_node *)malloc(sizeof(t_node));
	if (!curr)
		return (0);
	curr -> next = NULL;
	curr -> prev = NULL;
	curr -> index = index;
	curr -> data = data;
	
	return (curr);
}
