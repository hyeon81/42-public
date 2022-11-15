/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:03 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/15 15:36:54 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] && s2[i]) && (i < n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_sorted_list(t_stack *a, t_stack *b)
{
	t_node	*curr;
	int		val;

	if (b->head->next != b->tail)
		ft_exit("KO\n");
	curr = a->head->next;
	val = curr->index;
	curr = curr -> next;
	while (curr != a->tail)
	{
		if (val > curr->index)
			ft_exit("KO\n");
		else
			val = curr->index;
		curr = curr -> next;
	}
	ft_exit("OK\n");
}

void	run_command(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(a, b, 0);
	else
		error_exit();
}

void	read_line(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		run_command(line, a, b);
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a, &b);
	make_argv(ac, av, &a, 1);
	make_index(&a);
	is_overlapped(&a);
	read_line(&a, &b);
	check_sorted_list(&a, &b);
	return (0);
}
