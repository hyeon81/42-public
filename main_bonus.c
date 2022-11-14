#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] && s2[i]) && (i < n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_sorted_list(t_stack *a)
{
	t_node	*curr;
	int		val;

	curr = a->head->next;
	val = curr->index;
	curr = curr -> next;
	while (curr != a->tail)
	{
		if (val > curr->index)
		{
			ft_putstr("K0\n");
			exit(0);
		}
		else
			val = curr->index;
		curr = curr -> next;
	}
	return (0);
}

void	run_command(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(a, b, 0);
	else
		error_exit();
}

void	read_line(t_stack *a, t_stack *b)
{
	char	*line;
	//stdin으로 들어온 값을 읽어준다.
	while (1)
	{
		line = get_next_line(0);
		run_command(line);
		free(line);
	}
}

int main(int ac, char **av)
{
    //av를 a스택에 잘 쌓아준다.
    t_stack	a;
	t_stack	b;

	ft_init_stack(&a, &b);
	make_argv(ac, av, &a, 1);
	make_index(&a);
	is_overlapped(&a);
	is_sorted(&a);

	//read_line
	read_line(a, b);
	is_sorted_list(a);
	return (0);
}
