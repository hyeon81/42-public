/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:06:17 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:09:05 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*dest;

	i = 0;
	dest = dst;
	s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
