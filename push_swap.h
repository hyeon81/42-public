/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:06:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/24 19:18:23 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
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
    int    len;
} t_stack;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
t_node	*ft_lstnew(int data);

#endif