/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/08 20:08:33 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("%d\n", curr -> index);
		curr = curr -> next;
	} 
}

void sort_three_list(t_stack *stack)
{
	int index0;
	int index1;
	int index2;

	index0 = stack->a_head->next->index;
	index1 = stack->a_head->next->next->index;
	index2 = stack->a_tail->prev->index;

	if ((index0 > index1) && (index1 > index2) && (index0 > index2))
	{
		sa(stack->a_head);
		rra(stack);
	}
	//3 1 2
	else if ((index0 > index1) && (index2 > index1) && (index0 > index2))
		ra(stack);
	//2 1 3
	else if ((index0 > index1) && (index1 < index2) && (index0 < index2))
		sa(stack->a_head);
	//2 3 1
	else if ((index0 < index1) && (index1 > index2) && (index0 > index2))
		rra(stack);
	//1 3 2
	else if ((index0 < index1) && (index1 > index2) && (index0 < index2))
	{
		sa(stack->a_head);
		ra(stack);
	}
	
}

void a_to_b(t_stack *stack, int i, int chunk)
{
	int j;
	int top;
	
	j = 0;
	while (i < stack->size)
	{
		top = stack->a_head->next->index;
		if (top <= i)
		{
			pb(stack);
			i++;
		}
		else if (top <= chunk + i)
		{
			pb(stack);
			rb(stack);
			i++;
		}
		else if (top > chunk + i)
		{
			ra(stack);
		}
	}
}

void b_to_a(t_stack *stack)
{
	int max = stack->size - 1;
	int top;
	t_node *curr;
	int i = 0;
	while (max >= 0)
	{
		curr = stack->b_head->next;
		while (curr->next != 0)
		{
			if (curr->index == max)
				break;
			curr = curr -> next;
			i++;
		}
		top = stack->b_head->next->index;
		if (top == max)
		{
			pa(stack);
			max--;
		}
		else if (i > (stack->size / 2))
			rrb(stack);
		else
			rb(stack);
	}
}

int main(int ac, char **av)
{
	t_stack stack;
	int size = 0;
	int i;
	int idx;

	//예외 처리 필요
	if (ac < 2) //인자가 없음
		ft_exit();
	i = 1;
	idx = 0;
	ft_init_stack(&stack);
	while (i < ac)
	{
		char **tmp_arr;
		tmp_arr = ft_split(av[i], ' ');
		idx = 0;
		while (tmp_arr[idx] != 0)
		{
			insert_node_bottom(ft_atoi(tmp_arr[idx]), stack.a_tail);
			idx++;
			size++;
		}
		i++;
	}
	
	int arr[size];
	int idx_arr[size];
	ft_memset(arr, 0, size);
	t_node *curr;
	curr = stack.a_head->next;
	i = 0;
	while (i < size)
	{
		arr[i] = curr->index;
		curr = curr->next;
		i++;
	}
	//중복된 값 없는지 체크
	is_overlapped(arr, size);
	//정렬되어있는지 체크
	is_sorted(arr, size);
	make_index_arr(arr, idx_arr, size);
	stack.size = size;

	i = 0;
	curr = stack.a_head->next;
	while (i < size)
	{
		curr->index = idx_arr[i];
		curr = curr->next;
		i++;
	}
	//push_swap
	//under 3
	if (size == 2)
	{
		if (stack.a_head->index > stack.a_head->next->index)
			sa(stack.a_head);
		return (0);
	}
	if (size == 3)
	{
		sort_three_list(&stack);
		return (0);
	}
	// a_to_b(&stack, 0, 15);
	printf("===================\n");
	// show(stack.b_head, stack.b_tail);
	printf("===================\n");
	// b_to_a(&stack);
	// show(stack.a_head, stack.a_tail);
	// printf("===================\n");
	// show(stack.b_head, stack.b_tail);
	return (0);
}