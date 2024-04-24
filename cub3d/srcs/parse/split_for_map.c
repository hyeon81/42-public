/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:48:32 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/22 15:37:12 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**make_arr(char const *s, char c)
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
		if (s[i] == c)
			count++;
		i++;
	}
	arr = (char **)malloc(sizeof(char *) * (count + 2));
	return (arr);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
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

char	**split_for_map(char const *s, char c)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	len = 0;
	arr = make_arr(s, c);
	if (arr == NULL)
		return (NULL);
	while (*s)
	{
		len = word_len(s, c);
		arr[i] = ft_strdup_for_split(s, len);
		if (arr[i] == NULL)
			return (arr);
		s += len;
		if (*s)
			s++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
