/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:11:10 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/06/05 01:19:16 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1));
	if (!str)
		return 0;
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