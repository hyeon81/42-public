/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:52:13 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/06 13:58:40 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b_ptr;
	size_t i;

	b_ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_ptr[i] = c;
		i++;
	}
	return (b_ptr);
}

// int main()
// {
// 	char arr[] = "i'm so hungry";

// 	memset(arr, 'c', 10 * sizeof(char));
// 	printf("%s\n", arr);	
// 	ft_memset(arr, 'c', 10 * sizeof(char));
// 	printf("%s\n", arr);	
// }