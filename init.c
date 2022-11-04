#include "push_swap.h"

void make_index_arr(int arr[], int *i_arr, int size)
{
	int i = 0;
	int j = 0;
	int sorted[size];
	ft_memset(sorted, 0, size);
	ft_memset(i_arr, 0, size);
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort(sorted, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
				i_arr[i] = j;
			j++;
		}
		i++;
	}
	/*for(int i = 0; i < size; i++)
	{
		printf("sorted: %d\n", index[i]);
	}*/
}

void ft_init_stack(t_stack *stack)
{
	stack->a_head = ft_lstnew(-1);
	stack->a_tail = ft_lstnew(-1);
	stack->b_head = ft_lstnew(-1);
	stack->b_tail = ft_lstnew(-1);

	stack->a_head->next = stack->a_tail;
	stack->a_head->prev = stack->a_head;
	stack->a_tail->next = stack->a_tail;
	stack->a_tail->prev = stack->a_head;

	stack->b_head->next = stack->b_tail;
	stack->b_head->prev = stack->b_head;
	stack->b_tail->next = stack->b_tail;
	stack->b_tail->prev = stack->b_head;
}