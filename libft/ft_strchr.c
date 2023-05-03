/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:02:42 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:08:36 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (src[i])
	{	
		if (src[i] == (unsigned char)c)
			return (&src[i]);
		i++;
	}
	if (!c)
		return (&src[i]);
	return (NULL);
}
