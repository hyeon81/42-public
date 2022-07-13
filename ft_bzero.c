/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:24:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 18:41:33 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	i = 0;
	s_ptr = (unsigned char *)s;
	while (i < n)
	{
		s_ptr[i] = 0;
		i++;
	}
}

int main ()
{
	int ptr[4] = {1,2,3,4};
	ft_bzero(ptr, 25);

	for(int i = 0; i < 4; i++)
	{
		printf("%d", ptr[i]);
	}
}