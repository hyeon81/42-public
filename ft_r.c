#include "push_swap.h"

void ra(t_stack *stack)
{
    if (stack->a_head->next->index == -1)
        return ;
    ft_r(stack->a_head, stack->a_tail);
    ft_putstr("ra\n");
}

void rb(t_stack *stack)
{
    if (stack->b_head->next->index == -1)
        return ;
    ft_r(stack->b_head, stack->b_tail);
    ft_putstr("rb\n");
}

void rr(t_stack *stack)
{
    if (stack->b_head->next->index == -1 || stack->a_head->next->index == -1)
        return ;
    ra(stack);
    rb(stack);
    ft_putstr("rr\n");
}

void ft_r(t_node *head, t_node *tail)
{
    int temp;

    temp = head->next->index;
    remove_node_top(head);
    insert_node_bottom(temp, tail);
}