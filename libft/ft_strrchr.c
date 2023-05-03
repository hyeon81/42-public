/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:59:12 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:08:18 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*n;
	char		*src;

	i = 0;
	n = NULL;
	src = (char *)s;
	while (src[i])
	{
		if (src[i] == (unsigned char)c)
			n = &src[i];
		i++;
	}
	if (src[i] == (unsigned char)c)
		n = &src[i];
	return ((char *)n);
}
