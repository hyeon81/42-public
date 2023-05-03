/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:18:52 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:09:07 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*src;
	unsigned char	cc;

	idx = 0;
	src = (unsigned char *)s;
	cc = (unsigned char)c;
	while (idx < n)
	{
		if (src[idx] == cc)
			return ((void *)s + idx);
		idx++;
	}
	return (0);
}
