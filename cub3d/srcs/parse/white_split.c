/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:39:40 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/22 15:38:06 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**make_arr(char const *s)
{
	int		i;
	int		count;
	char	**arr;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (ft_is_space(s[i]) == 0)
		{
			while (s[i] && ft_is_space(s[i]) == 0)
				i++;
			count++;
		}
		else
			i++;
	}
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	return (arr);
}

static int	word_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]) != 0)
		i++;
	return (i);
}

static char	*ft_strdup_for_split(char const *str, int len)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (i < len && str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**white_split(char const *s)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	len = 0;
	arr = make_arr(s);
	if (arr == NULL)
		return (NULL);
	while (*s)
	{
		if (ft_is_space(*s) != 0)
		{
			len = word_len(s);
			arr[i] = ft_strdup_for_split(s, len);
			if (arr[i] == NULL)
				return (free_all(arr));
			s += len;
			i++;
		}
		else
			s++;
	}
	arr[i] = 0;
	return (arr);
}
