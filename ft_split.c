/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:23:20 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/06/08 22:12:44 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
// #include "libft.h"

int get_len(char* s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break;
		while (s[i] != c) 
			i++;
		len++;
	}
	return (len);
}

char *make_arr(char* s, char c, int i)
{
	char *arr;
	int idx;
	int j;

	idx = 0;
	j = i;
	while (s[j] != c && s[j] != 0)
		j++;
	
	arr = (char*)malloc(sizeof(char) * (j - i + 1));
	if (!arr)
		return 0;
	while (s[i] != c && s[i] != 0)
	{
		arr[idx] = s[i];
		idx++;
		i++;
	}
	arr[idx] = '\0';
	return (arr);
}

char **ft_split(char const *s, char c)
{
	char **arr;
	int i;
	int idx;

	arr = (char **)malloc(sizeof(char*)*(get_len((char*)s, c) + 1));

	if (!arr)
		return 0;
	i = 0;
	idx = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != 0)
		{
			arr[idx] = make_arr((char*)s, c, i);
			idx++;
		}
		while (s[i] != c && s[i] != 0)
			i++;
	}
	arr[idx] = 0;
	return (arr);
}


// int main()
// {
// 	char *string = "      split       this for   me  !       ";
// 	char **result = ft_split(string, ' ');
// 	printf("%s", result[0]);
// }