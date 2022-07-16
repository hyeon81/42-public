/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:38:22 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/16 16:16:59 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*des_p;
	unsigned char	*src_p;

	i = 0;
	des_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (des_p == src_p)
		return (des_p);
	while (i < n)
	{
		des_p[i] = src_p[i];
		i++;
	}
	return (des_p);
}
