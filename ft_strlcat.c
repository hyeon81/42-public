/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:41:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/16 13:06:07 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;
	size_t	j;

	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	i = d_size;
	j = 0;
	if (d_size >= size)
		return (size + s_size);
	while (src[j] != '\0' && (i + 1 < size))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (d_size + s_size);
}
