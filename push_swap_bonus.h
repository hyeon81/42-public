
#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
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

//require_remove
void	show(t_stack *a);

//libft
int		ft_atoi(char *str, int i, int sign);
int		ft_isdigit(int c);
void	ft_putstr(char *s);
t_node	*ft_lstnew(int index);
t_node	*ft_init_lstnew(int data, int index);
char	**ft_split(char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

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

//command list
void	sa(t_stack *a, int flag);
void	sb(t_stack *b, int flag);
void	ss(t_stack *a, t_stack *b, int flag);
void	ft_s(t_stack *s, int flag);
void	pa(t_stack *a, t_stack *b, int flag);
void	pb(t_stack *a, t_stack *b, int flag);
void	ft_p(t_stack *pop, t_stack *push, int flag);
void	ra(t_stack *a, int flag);
void	rb(t_stack *b, int flag);
void	rr(t_stack *a, t_stack *b, int flag);
void	ft_r(t_stack *s, int flag);
void	rra(t_stack *a, int flag);
void	rrb(t_stack *b, int flag);
void	rrr(t_stack *a, t_stack *b, int flag);
void	ft_rr(t_stack *s, int flag);

#endif