/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:38:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/05/23 18:12:07 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	unsigned char *uc1;
	unsigned char *uc2;

	uc1 = (unsigned char*)s1;
	uc2 = (unsigned char*)s2;
	i = 0;
	// if (n <= 0)
	// 	return (0);
	while ((uc1[i] && uc2[i]) && (i < n - 1))
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i++;
	}
	return (uc1[i] - uc2[i]);
}
