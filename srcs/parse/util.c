/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:32:46 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/22 15:38:16 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*a;

	i = 0;
	a = b;
	while (len)
	{
		a[i++] = c;
		len--;
	}
	return (b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	strs_len(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ss;
	int				i;

	ss = s;
	i = 0;
	while (n)
	{
		ss[i++] = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(size * count);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (count * size));
	return (tmp);
}
