/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/31 20:02:13 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

void show (t_node *head, t_node *tail)
{
	t_node *curr = head -> next;
	while (curr != tail)
	{
		printf("%d\n", curr -> data);
		curr = curr -> next;
	} 
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
	exit(0);
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
				ft_exit();
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

	stack->a_head->type = 1;
	stack->b_head->type = 1;
	stack->a_tail->type = 1;
	stack->b_tail->type = 1;
}

int is_sorted_list(t_node *head, t_node *tail)
{
	t_node *curr;
	curr = head->next;
	int val = curr->data;
	curr = curr -> next;

	while (curr != tail)
	{
		if (val > curr->data)
			return (0);
		else
			val = curr->data;
		curr = curr -> next;
	}
	return (1);
}

void sort_three_list(t_node *head, t_node *tail)
{
	int data0;
	int data1;
	int data2;

	data0 = head->next->data;
	data1 = head->next->next->data;
	data2 = tail->prev->data;

	if ((data0 > data1) && (data1 > data2) && (data0 > data2))
	{
		sa(head);
		rra(head, tail);
	}
	//3 1 2
	else if ((data0 > data1) && (data2 > data1) && (data0 > data2))
		ra(head, tail);
	//2 1 3
	else if ((data0 > data1) && (data1 < data2) && (data0 < data2))
		sa(head);
	//2 3 1
	else if ((data0 < data1) && (data1 > data2) && (data0 > data2))
		rra(head, tail);
	//1 3 2
	else if ((data0 < data1) && (data1 > data2) && (data0 < data2))
	{
		sa(head);
		ra(head, tail);
	}
	
}

int main(int ac, char **av)
{
	t_stack stack;
	int size;
	int arr[ac - 1];
	int i = 0;

	size = ac - 1;
	//예외 처리 필요
	if (ac < 2)
		ft_exit();
	ft_memset(arr, 0, size);
	while (i < size)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	//중복된 값 없는지 체크
	is_overlapped(arr, size);
	//정렬되어있는지 체크
	is_sorted(arr, size);

	i = 0;
	ft_init_stack(&stack);
	while (i < size)
	{
		insert_node_bottom(arr[i], stack.a_tail);
		i++;
	}

	//push_swap
	//under 3
	if (size == 2)
	{
		if (stack.a_head->data > stack.a_head->next->data)
			sa(stack.a_head);
	}
	if (size == 3)
	{
		sort_three_list(stack.a_head, stack.a_tail);
	}
	
	
	show(stack.a_head, stack.a_tail);
	printf("===================\n");
	show(stack.b_head, stack.b_tail);
	return (0);
}