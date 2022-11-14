/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:06:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/14 21:26:04 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				index;
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

//require_remove
void	show(t_stack *a);

//libft
int		ft_atoi(char *str, int i, int sign);
int		ft_isdigit(int c);
void	ft_putstr(char *s);
t_node	*ft_lstnew(int index);
t_node	*ft_init_lstnew(int data, int index);
char	**ft_split(char *s, char c);

//init
void	ft_init_stack(t_stack *a, t_stack *b);
void	make_argv(int ac, char **av, t_stack *a, int i);
void	make_index(t_stack *a);
void	is_sorted(t_stack *a);
void	is_overlapped(t_stack *a);

//main
void	error_exit(void);

//push_pop
void	insert_node_top(int index, t_node *head);
void	insert_node_bottom(int index, t_node *tail);
void	remove_node_top(t_node *head);
void	remove_node_bottom(t_node *tail);
void	insert_new_node(int data, int index, t_node *tail);

//sort
void	a_to_b(t_stack *a, t_stack *b, int i, int chunk);
void	make_b(t_stack *b, int max, int i);
void	b_to_a(t_stack *a, t_stack *b);
void	sort_under_five(t_stack *a, t_stack *b);
void	sort_over_five(t_stack *a, t_stack *b);
int	check_descending(t_stack *a, int idx, int i, int down);

//command list
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ft_s(t_stack *s);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ft_p(t_stack *pop, t_stack *push);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ft_r(t_stack *s);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ft_rr(t_stack *s);

#endif