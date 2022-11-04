/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:06:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/04 20:40:44 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
    int index;
    int data;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    int size;
    t_node *a_head;
    t_node *a_tail;
    t_node *b_head;
    t_node *b_tail;
} t_stack;

//libft
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
t_node	*ft_lstnew(int index);
void ft_putstr(char *s);
char	**ft_split(char const *s, char c);

//check_valid
void is_sorted(int arr[], int len);
void is_overlapped(int arr[], int len);
int is_sorted_list(t_node *head, t_node *tail);

//init
void make_index_arr(int arr[], int *i_arr, int size);
void ft_init_stack(t_stack *stack);

//utils
void ft_exit();
void quick_sort(int arr[], int left, int right);

//push_pop
void insert_node_top(int index, t_node *head);
void insert_node_bottom(int index, t_node *tail);
void remove_node_top(t_node *head);
void remove_node_bottom(t_node *tail);

//command list
void sa(t_node *a_head);
void sb(t_node *b_head);
void ss(t_stack *stack);
void ft_s(t_node *head);
void pa(t_stack *stack);
void pb(t_stack *stack);
void ft_p(t_node *head1, t_node *head2);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *stack);
void ft_r(t_node *head, t_node *tail);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack);
void ft_rr(t_node *head, t_node *tail);

#endif