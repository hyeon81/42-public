/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:44 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 19:05:15 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	i = 0;
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (i < n)
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i++;
	}
	return (0);
}

int main()
{
    char *s1 = "abcdefg";
    char *s2 = "abcd";
    char *s3 = "1";
    char *s4 = "";
    char *s5 = "abcdefg";

    printf("%d: %d\n", ft_memcmp(s1, s2, 7), memcmp(s1, s2, 7));
    printf("%d: %d\n", ft_memcmp(s1, s2, 2), memcmp(s1, s2, 2));
    printf("%d: %d\n", ft_memcmp(s1, s3, 7), memcmp(s1, s3, 7));
    printf("%d: %d\n", ft_memcmp(s1, s4, 7), memcmp(s1, s4, 7));
    printf("%d: %d\n", ft_memcmp(s1, s5, 7), memcmp(s1, s5, 7));
}