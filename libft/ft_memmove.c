/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:24:18 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:09:01 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (++i < len)
			dest[i] = s[i];
	}
	else
	{
		while (len)
		{
			dest[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}
