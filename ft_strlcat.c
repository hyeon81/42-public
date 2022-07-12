/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:55:14 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/05/25 19:41:48 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_size;
	unsigned int	s_size;
	unsigned int	i;
	unsigned int	j;

	d_size = 0;
	s_size = 0;
	while (dest[d_size] != '\0')
		d_size++;
	while (src[s_size] != '\0')
		s_size++;
	i = d_size;
	j = 0;
	if (d_size < size)
	{
		while (src[j] != '\0' && (i + 1 < size))
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (d_size + s_size);
	}
	return (size + s_size);
}
