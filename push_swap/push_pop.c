/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:51:02 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 19:57:51 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_node_top(t_node *head)
{
	t_node	*node;
	t_node	*next;

	node = head -> next;
	next = node -> next;
	head -> next = node -> next;
	next -> prev = head;
	free(node);
}

void	remove_node_bottom(t_node *tail)
{
	t_node	*node;
	t_node	*prev;

	node = tail -> prev;
	prev = node -> prev;
	tail -> prev = node -> prev;
	prev -> next = tail;
	free(node);
}

void	insert_node_top(int index, t_node *head)
{
	t_node	*node;
	t_node	*curr;

	node = ft_lstnew(index);
	curr = head -> next;
	curr -> prev -> next = node;
	node -> prev = curr -> prev;
	curr -> prev = node;
	node -> next = curr;
}

void	insert_node_bottom(int index, t_node *tail)
{
	t_node	*node;
	t_node	*curr;

	node = ft_lstnew(index);
	curr = tail -> prev;
	curr -> next -> prev = node;
	node -> next = curr -> next;
	curr -> next = node;
	node -> prev = curr;
}

void	insert_new_node(int data, int index, t_node *tail)
{
	t_node	*node;
	t_node	*curr;

	node = ft_init_lstnew(data, index);
	curr = tail -> prev;
	curr -> next -> prev = node;
	node -> next = curr -> next;
	curr -> next = node;
	node -> prev = curr;
}
