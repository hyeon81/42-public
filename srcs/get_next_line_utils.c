/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:42 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/26 20:14:11 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != 0)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	error_occur(int flag)
{
	if (flag == -1)
		printf("You escape!");
	if (flag == -2)
		printf("Error! argument is only one\n");
	if (flag == -3)
		printf("Error! map is not surrounded by wall\n");
	if (flag == 0)
		printf("Error! Element is not enough\n");
	if (flag == 1)
		printf("Error! P should be one\n");
	if (flag == 2)
		printf("Error! C does not exist\n");
	if (flag == 3)
		printf("Error! E should be one\n");
	system("leaks so_long");
	exit(0);
	return (0);
}
