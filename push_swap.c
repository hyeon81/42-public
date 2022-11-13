/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/13 22:05:02 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

void show (t_node *head, t_node *tail)
{
	t_node *curr = head -> next;

	while (curr != tail)
	{
		printf("%d\n", curr -> index);
		curr = curr -> next;
	} 
}

int main(int ac, char **av)
{
	t_stack stack;
	int chunk;

	ft_init_stack(&stack);
	make_argv(ac, av, &stack);
	make_index(&stack);
	show(stack.a_head, stack.a_tail);
	if (ac < 7)
		sort_under_five(&stack);
	chunk = 0.000000053 * (stack.size * stack.size) + 0.03 * stack.size + 14.5;
	a_to_b(&stack, 0, chunk);
	// show(stack.b_head, stack.b_tail);
	// printf("===================\n");
	b_to_a(&stack);
	// show(stack.a_head, stack.a_tail);
	return (0);
}