#include "push_swap.h"

void ra(t_stack *stack)
{
    ft_r(stack->a_head, stack->a_tail);
    ft_putstr("ra\n");
}

void rb(t_stack *stack)
{
    ft_r(stack->b_head, stack->b_tail);
    ft_putstr("rb\n");
}

void rr(t_stack *stack)
{
    ft_r(stack->a_head, stack->a_tail);
    ft_r(stack->b_head, stack->b_tail);
    ft_putstr("rr\n");
}

void ft_r(t_node *head, t_node *tail)
{
    int temp;

    if (head->next->index == -1)
        return ;
    temp = head->next->index;
    remove_node_top(head);
    insert_node_bottom(temp, tail);
}