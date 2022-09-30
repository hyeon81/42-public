/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_suffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:25:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/30 16:28:21 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

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

void	check_suffix(char *filename)
{
	char	*suffix;

	if (filename == 0)
		error_occur(-2, 0);
	suffix = ft_strrchr(filename, '.');
	if (suffix == 0)
		error_occur(-2, 0);
	if (ft_strncmp(suffix, ".ber", 5) != 0)
		error_occur(-2, 0);
}

void	value_init(t_vars *vars)
{
	vars->p = 0;
	vars->c = 0;
	vars->e = 0;
	vars->get_item = 0;
	vars->move_count = 0;
}

void	insert_map(t_vars *vars, char *m_line)
{
	int	i;
	int	m;
	int	j;

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
	ft_free_m_line(m_line);
}
