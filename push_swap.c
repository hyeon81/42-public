/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/24 19:31:07 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void remove_node(t_node *head, t_node *tail) 
{
	t_node *node = head -> next;
	head -> next = node -> next;

	t_node *next = node -> next;
	next -> prev = head;

	free(node);
}

void insert_node(int data, t_node *head, t_node *tail)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));
	node->data = data;

	t_node *cur;
	cur = head -> next;
	while (cur != tail)
	{
		cur = cur -> next;
	}
	// t_node *prev = cur -> prev;
	cur -> prev -> next = node;
	node -> prev = cur -> prev;
	cur -> prev = node;
	node -> next = cur;    
}

void show (t_node *head, t_node *tail)
{
	t_node *cur = head -> next;
	while (cur != tail)
	{
		printf("%d\n", cur -> data);
		cur = cur -> next;
	} 
}

void ft_s(t_node *head, char c)
{
	int temp;

	temp = head->next->next->data;
	head->next->next->data = head->next->data;
	head->next->data = temp;
}

void is_sorted(int arr[], int len)
{
	int i = 1;
	int val = arr[0];

	while (i < len)
	{
		if (val > arr[i])
			return ;
		else
			val = arr[i];
		i++;
	}
	write(1, "array is sorted", 15);
	exit (0);
}

void is_overlapped(int arr[], int len)
{
	int i = 0;
	int j;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			// printf("%d, %d, %d, %d\n", i, j, arr[i], arr[j]);
			if (arr[i] == arr[j])
			{
				write(1, "number is overlapped", 20);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void ft_init_stack(t_stack *stack)
{
	stack->a_head = ft_lstnew(0);
	stack->a_tail = ft_lstnew(0);
	stack->b_head = ft_lstnew(0);
	stack->b_tail = ft_lstnew(0);

	stack->a_head->next = stack->a_tail;
	stack->a_head->prev = stack->a_head;
	stack->a_tail->next = stack->a_tail;
	stack->a_tail->prev = stack->a_head;

	stack->b_head->next = stack->b_tail;
	stack->b_head->prev = stack->b_head;
	stack->b_tail->next = stack->b_tail;
	stack->b_tail->prev = stack->b_head;
}

int main(int ac, char **av)
{
	t_stack stack;
	int arr[ac - 1];
	int i = 0;

	//예외 처리 필요
	if (ac < 2)
	{
		write(1, "Argument Error\n", 15);
		exit(1);
	}
	ft_memset(arr, 0, ac - 1);
	while (i < ac - 1)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	//중복된 값 없는지 체크
	is_overlapped(arr, ac - 1);
	//정렬되어있는지 체크
	is_sorted(arr, ac - 1);

	// i = 0;
	// while (i < ac - 1)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	//양방향 링크드 리스트 사용


	i = 0;
	ft_init_stack(&stack);
	while (i < ac - 1)
	{
		insert_node(arr[i], stack.a_head, stack.a_tail);
		i++;
	}
	show(stack.a_head, stack.a_tail);
	return (0);
}