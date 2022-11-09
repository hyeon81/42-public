/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:01:48 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/11/09 22:10:11 by hyeokim2         ###   ########.fr       */
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

void sort_four_list(t_stack *stack)
{
	t_node *curr;
	int min;
	int top;
	
	// printf("here");
	min = stack->a_head->next->index;
	curr = stack->a_head->next;
	while (curr->index != -1)
	{
		if (min > curr->index)
			min = curr->index;
		curr = curr -> next;
	}
	// printf("min: %d\n", min);
	while (1)
	{
		top = stack->a_head->next->index;
		if (top == min)
		{
			pb(stack);
			break;
		}
		ra(stack);
	}
	sort_three_list(stack);
	pa(stack);
	// show(stack->a_head, stack->a_tail);
}

void sort_five_list(t_stack *stack)
{
	t_node *curr;
	int min;
	int top;
	int i = 0;
	// printf("here");
	while (i < 2)
	{
		min = stack->a_head->next->index;
		curr = stack->a_head->next;
		while (curr->index != -1)
		{
			if (min > curr->index)
				min = curr->index;
			curr = curr -> next;
		}
		// printf("min: %d\n", min);
		while (1)
		{
			top = stack->a_head->next->index;
			if (top == min)
			{
				pb(stack);
				break;
			}
			ra(stack);
		}
		i++;
	}
	sort_three_list(stack);
	pa(stack);
	pa(stack);
	// show(stack->a_head, stack->a_tail);
}

void a_to_b(t_stack *stack, int i, int chunk)
{
	int top;
	int rb_flag = 0;
	
	while (i < stack->size)
	{
		top = stack->a_head->next->index;
		if (top > chunk + i)
		{
			if (rb_flag)
			{
				rr(stack);
				rb_flag = 0;
			}
			else
				ra(stack);
		}
		if (rb_flag)
		{
			rb(stack);
			rb_flag = 0;
		}
		if (top <= i)
		{
			pb(stack);
			i++;
		}
		if (top > i && top <= chunk + i)
		{
			pb(stack);
			rb_flag = 1;
			i++;
		}
	}
}

void b_to_a(t_stack *stack)
{
	t_node *curr;
	int max = stack->size - 1;
	int top;
	int i = 0;
	int num = 1;
	curr = stack->b_head->next;
	while (curr->next != 0)
	{
		if (curr->index == max)
			break;
		curr = curr -> next;
		i++;
	}
	while (max >= 0)
	{
		top = stack->b_head->next->index;
		if (top == max - num && num <= 2)
		{
			pa(stack);
			ra(stack);
			num++;
		}
		if (top == max)
		{
			pa(stack);
			max = max - num;
			while (num > 1)
			{
				rra(stack);
				num--;
			}
			if (stack->a_head->next->index > stack->a_head->next->next->index && stack->a_head->next->next->index != -1)
				sa(stack->a_head);
			i = 0;
			curr = stack->b_head->next;
			while (curr->next != 0)
			{
				if (curr->index == max)
				break;
				curr = curr -> next;
				i++;
			}
		}
		else if (i > (max / 2))
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
	if (size == 4)
	{
		sort_four_list(&stack);
		return (0);
	}
	if (size == 5)
	{
		sort_five_list(&stack);
		return (0);
	}
	a_to_b(&stack, 0, 15);
	// printf("===================\n");
	// show(stack.b_head, stack.b_tail);
	// printf("===================\n");
	b_to_a(&stack);
	show(stack.a_head, stack.a_tail);
	printf("===================\n");
	show(stack.b_head, stack.b_tail);
	return (0);
}