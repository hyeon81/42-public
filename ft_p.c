#include "push_swap.h"

void pb(t_stack *stack)
{
    ft_p(stack->b_head, stack->a_head);
}

void pa(t_stack *stack)
{
    ft_p(stack->a_head, stack->b_head);
}

void ft_p(t_node *head1, t_node *head2)
{
    int temp;

    if (head2->next->type)
        return ;
    temp = head2->next->data;
    remove_node_top(head2);
    insert_node_top(temp, head1);
}