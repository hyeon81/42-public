/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:51:02 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/01 21:14:24 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void remove_node_top(t_node *head) 
{
	t_node *node = head -> next;
	head -> next = node -> next;

	t_node *next = node -> next;
	next -> prev = head;

	free(node);
}

void remove_node_bottom(t_node *tail)
{
	t_node *node = tail -> prev;
	tail -> prev = node -> prev;

	t_node *prev = node -> prev;
	prev -> next = tail;

	free(node);
}

void insert_node_top(int data, int index, t_node *head)
{
	t_node *node = ft_lstnew(data, index);
	t_node *curr;
	curr = head -> next;
	// while (cur != tail)
	// 	cur = cur -> next;
	curr -> prev -> next = node;
	node -> prev = curr -> prev;
	curr -> prev = node;
	node -> next = curr;    
}

void insert_node_bottom(int data, int index, t_node *tail)
{
	t_node *node = ft_lstnew(data, index);
	t_node *curr;
	// curr = head -> next;
	curr = tail -> prev;
	// while (curr != tail)
		// curr = curr -> next;
	curr -> next -> prev = node;
	node -> next = curr -> next;
	curr -> next = node;
	node -> prev = curr;    
}
