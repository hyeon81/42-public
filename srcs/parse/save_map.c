/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/22 18:51:32 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (0);
	return (1);
}

int	make_line(char *line, char **backup, t_check *check, int *direction)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && \
			line[i] != '\n' && line[i] != 'N' && line[i] != 'S' && line[i] != \
			'W' && line[i] != 'E')
			exit_with_err("Invalid map\n");
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || \
			line[i] == 'E')
		{
			*direction = line[i];
			check->path_count++;
			if (check->path_count > 1)
				exit_with_err("Player is not only one\n");
		}
		i++;
	}
	tmp = *backup;
	*backup = ft_strjoin(*backup, line);
	free(tmp);
	return (0);
}

int	parse_line(char *line, char **backup, t_check *check, int *direction)
{
	int	i;

	i = 0;
	if (check->count != 6)
		return (0);
	if (check->mapflag == 1)
	{
		make_line(line, backup, check, direction);
		return (0);
	}
	while (ft_is_space(line[i]) == 0)
			i++;
	if (!line[i])
		return (0);
	if (line[i] == '1')
	{
		check->mapflag = 1;
		make_line(line, backup, check, direction);
	}
	else
		exit_with_err("Invalid map\n");
	return (0);
}

int	save_map(char **backup, t_vars *vars, t_check *check)
{
	free(check->mapset);
	if (*backup)
	{
		vars->map = split_for_map(*backup, '\n');
		free(*backup);
		remove_newline(vars->map);
		check_valid(vars->map, vars->p, &(vars->col), &(vars->row));
	}
	else
		exit_with_err("Invalid map\n");
	return (0);
}

int	init_map(t_vars	*vars, int fd, t_check *check)
{
	char	*backup;
	char	*line;

	backup = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		parse_line(line, &backup, check, &(vars->p->direction));
		if (check->count == 6)
		{
			free(line);
			continue ;
		}
		else
			set_map(line, vars, check);
		free (line);
	}
	if (check->path_count != 1)
		exit_with_err("Invalid player\n");
	save_map(&backup, vars, check);
	return (0);
}
