#include "push_swap.h"

void ft_s(t_node *head)
{
	int temp;

	if (head->next->type)
		return ;
	temp = head->next->next->data;
	head->next->next->data = head->next->data;
	head->next->data = temp;
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

void ft_r(t_node *head, t_node *tail)
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

void ft_rr(t_node *head, t_node *tail)
{
    int temp;

    temp = head->next->data;
    remove_node_top(head);
    insert_node_bottom(temp, tail);
}

void command_list(char c1, char c2, t_stack *stack)
{
    if (c1 == 's' && c2 == 'a')
        ft_s(stack->a_head);
    else if (c1 == 's' && c2 == 'b')
        ft_s(stack->b_head);
    else if (c1 == 's' && c2 == 's')
    {
        ft_s(stack->a_head);
        ft_s(stack->b_head);
    }
    else if (c1 == 'p' && c2 == 'a')
        ft_p(stack->a_head, stack->b_head);
    else if (c1 == 'p' && c2 == 'b')
        ft_p(stack->b_head, stack->a_head);
    else if (c1 == 'r' && c2 == 'a')
        ft_r(stack->a_head, stack->a_tail);
    else if (c1 == 'r' && c2 == 'b')
        ft_r(stack->b_head, stack->b_tail);
    else if (c1 == 'r' && c2 == 'r')
    {
        ft_r(stack->a_head, stack->a_tail);
        ft_r(stack->b_head, stack->b_tail);
    }
    else if (c1 == 'R' && c2 == 'A')
        ft_rr(stack->a_head, stack->a_tail);
    else if (c1 == 'R' && c2 == 'B')
        ft_rr(stack->b_head, stack->b_tail);
    else if (c1 == 'R' && c2 == 'R')
    {
        ft_rr(stack->a_head, stack->a_tail);
        ft_rr(stack->b_head, stack->b_tail);
    }
}