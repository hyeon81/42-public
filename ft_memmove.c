/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:38:41 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/16 13:09:55 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*des_p;
	unsigned char	*src_p;

	i = -1;
	des_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (des_p == src_p)
		return (des_p);
	if (des_p <= src_p)
	{
		while (++i < len)
			des_p[i] = src_p[i];
	}
	else
	{
		while (len > 0)
		{
			des_p[len - 1] = src_p[len - 1];
			len--;
		}
	}
	return (des_p);
}
