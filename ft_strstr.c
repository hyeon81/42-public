/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:41:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/04 22:16:00 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
size_t	ft_strlen(const char *str);

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	j = 0;
	int len = ft_strlen(haystack);
	while ((haystack[i] != 0) && (i < len))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			j++;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
