/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:48:14 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/15 17:26:19 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *a, t_stack *b)
{
	a->head = ft_init_lstnew(0, -1);
	a->tail = ft_init_lstnew(0, -1);
	b->head = ft_init_lstnew(0, -1);
	b->tail = ft_init_lstnew(0, -1);
	a->head->next = a->tail;
	a->head->prev = a->head;
	a->tail->next = a->tail;
	a->tail->prev = a->head;
	b->head->next = b->tail;
	b->head->prev = b->head;
	b->tail->next = b->tail;
	b->tail->prev = b->head;
}

void	make_argv(int ac, char **av, t_stack *a, int i)
{
	int		idx;
	int		size;
	char	**tmp_arr;

	idx = 0;
	size = 0;
	if (ac < 2)
		ft_exit(NULL);
	while (i < ac)
	{
		tmp_arr = ft_split(av[i], ' ');
		if (tmp_arr[0] == NULL)
			error_exit();
		idx = 0;
		while (tmp_arr[idx] != 0)
		{
			insert_new_node(ft_atoi(tmp_arr[idx], 0, 1), 0, a->tail);
			idx++;
			size++;
		}
		ft_free_all(tmp_arr, ft_double_strlen(tmp_arr));
		i++;
	}
	a->size = size;
}

void	make_index(t_stack *a)
{
	t_node	*curr;
	t_node	*search;

	curr = a->head->next;
	while (curr != a->tail)
	{
		search = a->head->next;
		while (search != a->tail)
		{
			if (search->data < curr->data)
				curr->index++;
			search = search -> next;
		}
		curr = curr -> next;
	}
}

void	is_overlapped(t_stack *a)
{
	t_node	*curr;
	t_node	*search;

	curr = a->head->next;
	while (curr->next != a->tail)
	{
		search = curr->next;
		while (search != a->tail)
		{
			if (curr->index == search->index)
				error_exit();
			search = search->next;
		}
		curr = curr->next;
	}
}

void	is_sorted(t_stack *a)
{
	t_node	*curr;
	int		val;

	curr = a->head->next;
	val = curr->index;
	curr = curr -> next;
	while (curr != a->tail)
	{
		if (val > curr->index)
			return ;
		else
			val = curr->index;
		curr = curr -> next;
	}
	ft_exit(NULL);
}
