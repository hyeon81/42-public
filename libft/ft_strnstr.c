/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:16:34 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:08:24 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hst;

	i = 0;
	j = 0;
	hst = (char *)haystack;
	if (needle[i] == '\0')
		return (hst);
	if (len == 0)
		return (NULL);
	while (hst[i] != '\0' && i < len)
	{
		j = 0;
		if (hst[i] == needle[j])
		{
			while ((hst[i + j] == needle[j])
				&& (needle[j] != '\0') && (i + j < len))
				j++;
			if (needle[j] == '\0')
				return (&hst[i]);
		}
		i++;
	}
	return (NULL);
}
