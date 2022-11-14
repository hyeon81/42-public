/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 21:41:35 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	show(t_stack *a)
{
	t_node	*curr;

	curr = a->head->next;
	while (curr != a->tail)
	{
		printf("%d\n", curr -> index);
		curr = curr -> next;
	}
}

void	sort_over_five(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = 0.000000053 * (a->size * a->size) + 0.03 * a->size + 14.5;
	if (a->size == 500)
		chunk = 30;
	if (a->size == 100)
		chunk = 15;
	a_to_b(a, b, 0, chunk);
	b_to_a(a, b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a, &b);
	make_argv(ac, av, &a, 1);
	make_index(&a);
	is_overlapped(&a);
	is_sorted(&a);
	if (ac < 7)
		sort_under_five(&a, &b);
	sort_over_five(&a, &b);
	return (0);
}
