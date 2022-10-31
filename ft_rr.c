/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:46:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/31 20:01:29 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_node *a_head, t_node *a_tail)
{
    ft_rr(a_head, a_tail);
}

void rrb(t_node *b_head, t_node *b_tail)
{
    ft_rr(b_head, b_tail);
}

void rrr(t_stack *stack)
{
    ft_rr(stack->a_head, stack->a_tail);
    ft_rr(stack->b_head, stack->b_tail);
}

void ft_rr(t_node *head, t_node *tail)
{
    t_node *curr;
    int temp;

    curr = head -> next;
    while (curr->next != tail)
    {
        curr = curr -> next;
    }
    temp = curr->data;
    remove_node_bottom(tail);
    insert_node_top(temp, head);
}