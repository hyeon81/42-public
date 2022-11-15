/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/15 17:28:59 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_over_five(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = 0.000000053 * (a->size * a->size) + 0.03 * a->size + 14.5;
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
	if (a.size < 6)
		sort_under_five(&a, &b);
	else
		sort_over_five(&a, &b);
	return (0);
}
