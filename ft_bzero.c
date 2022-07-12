/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:24:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/06 14:22:16 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;
    unsigned char *s_ptr;

	i = 0;
    s_ptr = (unsigned char*)s;
	while (i < n)
	{
		s_ptr[i] = 0;
		i++;
	}
}

// int main ()
// {
// 	int ptr[4] = {1,2,3,4};
// 	ft_bzero(ptr, 30);

// 	for(int i = 0; i < 4; i++)
// 	{
// 		printf("%d", ptr[i]);
// 	}
// }