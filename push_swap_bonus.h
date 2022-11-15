/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:17 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/15 15:32:40 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"

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

//util1
int		ft_atoi(char *str, int i, int sign);
int		ft_isdigit(int c);
void	ft_putstr(char *s);
t_node	*ft_lstnew(int index);
t_node	*ft_init_lstnew(int data, int index);

//utils2
char	**ft_split(char *s, char c);
char	**ft_free_all(char **s, int idx);
int		ft_double_strlen(char **str);
void	error_exit(void);
void	ft_exit(char *s);

//init
void	ft_init_stack(t_stack *a, t_stack *b);
void	make_argv(int ac, char **av, t_stack *a, int i);
void	make_index(t_stack *a);
void	is_sorted(t_stack *a);
void	is_overlapped(t_stack *a);

//push_pop
void	insert_node_top(int index, t_node *head);
void	insert_node_bottom(int index, t_node *tail);
void	remove_node_top(t_node *head);
void	remove_node_bottom(t_node *tail);
void	insert_new_node(int data, int index, t_node *tail);

//command list
void	sa(t_stack *a, int flag);
void	sb(t_stack *b, int flag);
void	ss(t_stack *a, t_stack *b, int flag);
void	ft_s(t_stack *s);
void	pa(t_stack *a, t_stack *b, int flag);
void	pb(t_stack *a, t_stack *b, int flag);
void	ft_p(t_stack *pop, t_stack *push);
void	ra(t_stack *a, int flag);
void	rb(t_stack *b, int flag);
void	rr(t_stack *a, t_stack *b, int flag);
void	ft_r(t_stack *s);
void	rra(t_stack *a, int flag);
void	rrb(t_stack *b, int flag);
void	rrr(t_stack *a, t_stack *b, int flag);
void	ft_rr(t_stack *s);

#endif