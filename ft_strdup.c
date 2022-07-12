/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:11:07 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/05/31 19:02:49 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char*	ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	arr = (char*)malloc(sizeof(char) * (len + 1));
	
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
