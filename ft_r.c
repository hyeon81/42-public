#include "push_swap.h"

void ra(t_node *a_head, t_node *a_tail)
{
    ft_r(a_head, a_tail);
}

void rb(t_node *b_head, t_node *b_tail)
{
    ft_r(b_head, b_tail);
}

void rr(t_stack *stack)
{
    ft_r(stack->a_head, stack->a_tail);
    ft_r(stack->b_head, stack->b_tail);
}

void ft_r(t_node *head, t_node *tail)
{
    int temp;

    temp = head->next->data;
    remove_node_top(head);
    insert_node_bottom(temp, tail);
}