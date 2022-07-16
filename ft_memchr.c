/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:40 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/16 12:25:55 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc;

	uc = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (uc[i] == (unsigned char)c)
			return (&uc[i]);
		i++;
	}
	return (0);
}
