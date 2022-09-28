/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:33:04 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/28 21:22:53 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid(t_vars *vars, int i, int j)
{
	while (j < vars->h)
	{
		i = 0;
		while (i < vars->w)
		{
			if (!(vars->map[j][i] == 'P' || vars->map[j][i] == 'E' \
				|| vars->map[j][i] == '1' || vars->map[j][i] == '0' \
				|| vars->map[j][i] == 'C'))
				error_occur(0, vars);
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
	if (vars->p != 1)
		error_occur(1, vars);
	if (vars->c < 1)
		error_occur(2, vars);
	if (vars->e != 1)
		error_occur(3, vars);
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
				error_occur(-3, vars);
			if (vars->map[j][0] != '1')
				error_occur(-3, vars);
			if (vars->map[vars->h - 1][i] != '1')
				error_occur(-3, vars);
			if (vars->map[j][vars->w - 1] != '1')
				error_occur(-3, vars);
			i++;
		}
		j++;
	}
}

void	ft_check_sqaure(char *line, int width)
{
	if (width != ft_strlen(line))
	{
		free(line);
		error_occur(-4, 0);
	}
}

char	*read_line(int fd, t_vars *vars)
{
	char	*line;
	char	*m_line;
	char	*temp;

	vars->h = 1;
	line = get_next_line(fd);
	m_line = ft_strdup(line);
	vars->w = ft_strlen(line);
	while (line)
	{
		if (line == 0)
			break ;
		ft_check_sqaure(line, vars->w);
		temp = ft_strjoin(m_line, line);
		ft_free(&m_line, &temp, 1);
		(vars->h)++;
		free(line);
		line = get_next_line(fd);
	}
	return (m_line);
}

void	make_map(t_vars *vars, char *m_line, int i, int j)
{
	int	m;

	vars->map = (char **)malloc(sizeof(char *) * (vars->h + 1));
	if (!(vars->map))
	{
		free(m_line);
		exit(0);
	}
	while (++i < vars->h)
	{
		vars->map[i] = (char *)malloc(sizeof(char) * (vars->w + 1));
		if (!(vars->map[i]))
			ft_exit_free(vars);
	}
	i = -1;
	m = -1;
	while (++i < vars->h)
	{
		j = -1;
		while (++j < vars->w)
			vars->map[i][j] = m_line[++m];
		vars->map[i][j] = 0;
	}
	vars->map[i] = 0;
	free(m_line);
}
