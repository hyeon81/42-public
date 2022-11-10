/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:46:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/04 16:06:32 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *stack)
{
    if (stack-> a_head -> next -> index == -1)
        return ;
    ft_rr(stack->a_head, stack->a_tail);
    ft_putstr("rra\n");
}

void rrb(t_stack *stack)
{
    if (stack-> b_head -> next -> index == -1)
        return ;
    ft_rr(stack->b_head, stack->b_tail);
    ft_putstr("rrb\n");
}

void rrr(t_stack *stack)
{
    ft_rr(stack->a_head, stack->a_tail);
    ft_rr(stack->b_head, stack->b_tail);
    ft_putstr("rrr\n");
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
    temp = curr->index;
    remove_node_bottom(tail);
    insert_node_top(temp, head);
}