/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:06:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/25 21:33:04 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
    int type;
    int data;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *a_head;
    t_node *a_tail;
    t_node *b_head;
    t_node *b_tail;
} t_stack;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
t_node	*ft_lstnew(int data);
void command_list(char c1, char c2, t_stack *stack);
void insert_node_top(int data, t_node *head);
void insert_node_bottom(int data, t_node *tail);
void remove_node_top(t_node *head);
void remove_node_bottom(t_node *tail);
void ft_exit();

#endif