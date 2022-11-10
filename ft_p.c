#include "push_swap.h"

void pa(t_stack *stack)
{
    if (stack->b_head->next->index == -1)
        return ;
    ft_p(stack->a_head, stack->b_head);
    ft_putstr("pa\n");
}

void pb(t_stack *stack)
{
    if (stack->a_head->next->index == -1)
        return ;
    ft_p(stack->b_head, stack->a_head);
    ft_putstr("pb\n");
}

void ft_p(t_node *head1, t_node *head2)
{
    int temp;

    temp = head2->next->index;
    remove_node_top(head2);
    insert_node_top(temp, head1);
}