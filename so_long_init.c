/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long_init.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyeokim2 <hyeokim2@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/22 21:13:18 by hyeokim2		  #+#	#+#			 */
/*   Updated: 2022/09/22 21:41:34 by hyeokim2		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_vars *vars, char *m_line)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	m = 0;
	vars->map = (char **)malloc(sizeof(char *) * (vars->h + 1));
	while (i < vars->h)
	{
		vars->map[i] = (char *)malloc(sizeof(char) * (vars->w + 1));
		i++;
	}
	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (j < vars->w)
		{
			vars->map[i][j] = m_line[m];
			m++;
			j++;
		}
		i++;
	}
}

void	check_valid(t_vars *vars)
{
	int	j;
	int	i;

	j = 0;
	while (j < vars->h)
	{
		i = 0;
		while (i < vars->w)
		{
			if (!(vars->map[j][i] == 'P' || vars->map[j][i] == 'E' \
				|| vars->map[j][i] == '1' || vars->map[j][i] == '0' \
				|| vars->map[j][i] == 'C'))
				occur_error(-1);
			if (vars->map[j][i] == 'P')
				vars->p++;
			if (vars->map[j][i] == 'C')
				vars->c++;
			if (vars->map[j][i] == 'E')
				vars->e++;
			i++;
		}
		j++;
	}
	if (vars->p != 1 || vars->c < 1 || vars->e != 1)
		occur_error(-1);
}

void	check_wall_wrap(t_vars *vars)
{
	int	j;
	int	i;

	j = 0;
	while (j < vars->h)
	{
		i = 0;
		while (i < vars->w)
		{
			if (vars->map[0][i] != '1')
				occur_error(-1);
			if (vars->map[j][0] != '1')
				occur_error(-1);
			if (vars->map[vars->h - 1][i] != '1')
				occur_error(-1);
			if (vars->map[j][vars->w - 1] != '1')
				occur_error(-1);
			i++;
		}
		j++;
	}
}

void	init_value(t_vars *vars)
{
	vars->h = 1;
	vars->p = 0;
	vars->c = 0;
	vars->e = 0;
	vars->item = 0;
	vars->get_item = 0;
	vars->move_count = 0;
}

char	*read_line(int fd, t_vars *vars)
{
	char	*line;
	char	*m_line;
	char	*temp;

	line = get_next_line(fd);
	m_line = ft_strdup(line);
	vars->w = ft_strlen(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		printf("Gnl line : %s\n", line);
		if (line == 0)
			break ;
		if (vars->w != ft_strlen(line))
		{
			printf("Error!\n");
			return (0);
		}
		temp = ft_strjoin(m_line, line);
		ft_free(&m_line, &temp, 1);
		(vars->h)++;
		free(line);
	}
	return (m_line);
}
