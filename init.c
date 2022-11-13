#include "push_swap.h"

void make_argv(int ac, char **av, t_stack *stack)
{
	int i;
	int idx;
	int size;

	i = 1;
	idx = 0;
	size = 0;
	if (ac < 2) //인자가 없음
		ft_exit();
	while (i < ac)
	{
		char **tmp_arr;
		tmp_arr = ft_split(av[i], ' ');
		idx = 0;
		while (tmp_arr[idx] != 0)
		{
			insert_new_node(ft_atoi(tmp_arr[idx]), 0, stack->a_tail);
			idx++;
			size++;
		}
		i++;
	}
	stack->size = size;
}

void make_index(t_stack *stack)
{
	t_node *curr;
	t_node *search;

	curr = stack->a_head->next;
	while (curr != stack->a_tail)
	{
		search = stack->a_head->next;
		while (search != stack->a_tail)
		{
			if (search->data < curr->data)
				curr->index++;
			search = search -> next;
		}
		curr = curr -> next;
	}
}

// int *make_arr(t_stack *stack)
// {
// 	t_node *curr;
// 	int i;
// 	int arr[stack->size];
	
// 	curr = stack->a_head->next;
// 	ft_memset(arr, 0, stack->size);
// 	curr = stack->a_head->next;
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		arr[i] = curr->index;
// 		curr = curr->next;
// 		i++;
// 	}
// 	is_overlapped(arr, stack->size);
// 	is_sorted(arr, stack->size);
// 	return (arr);
// }


// void make_index(t_stack *stack, int *arr, int *idx_arr)
// {
// 	int i;
// 	int j;
// 	int sorted[stack->size];

// 	ft_memset(sorted, 0, stack->size);
// 	ft_memset(idx_arr, 0, stack->size);
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		sorted[i] = arr[i];
// 		i++;
// 	}
// 	quick_sort(sorted, 0, stack->size - 1);
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		j = 0;
// 		while (j < stack->size)
// 		{
// 			if (arr[i] == sorted[j])
// 				idx_arr[i] = j;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int *make_index_arr(t_stack *stack, int *arr)
// {
// 	t_node *curr;
// 	int i;
// 	int idx_arr[stack->size];

// 	make_index(stack, arr, idx_arr);
// 	i = 0;
// 	curr = stack->a_head->next;
// 	while (i < stack->size)
// 	{
// 		curr->index = idx_arr[i];
// 		curr = curr->next;
// 		i++;
// 	}
// 	return (idx_arr);
// }

void ft_init_stack(t_stack *stack)
{
	stack->a_head = ft_init_lstnew(0, -1);
	stack->a_tail = ft_init_lstnew(0, -1);
	stack->b_head = ft_init_lstnew(0, -1);
	stack->b_tail = ft_init_lstnew(0, -1);
	
	stack->a_head->next = stack->a_tail;
	stack->a_head->prev = stack->a_head;
	stack->a_tail->next = stack->a_tail;
	stack->a_tail->prev = stack->a_head;

	stack->b_head->next = stack->b_tail;
	stack->b_head->prev = stack->b_head;
	stack->b_tail->next = stack->b_tail;
	stack->b_tail->prev = stack->b_head;
}