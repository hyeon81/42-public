#include "push_swap.h"

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

int is_sorted_list(t_node *head, t_node *tail)
{
	t_node *curr;
	curr = head->next;
	int val = curr->index;
	curr = curr -> next;

	while (curr != tail)
	{
		if (val > curr->index)
			return (0);
		else
			val = curr->index;
		curr = curr -> next;
	}
	return (1);
}
