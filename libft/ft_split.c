/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:13:28 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:08:52 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		else
			i++;
	}
	arr = (char **)malloc(sizeof(char *) * (count + 1));
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

static char	**free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
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
		if (*s != c)
		{
			len = word_len(s, c);
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
