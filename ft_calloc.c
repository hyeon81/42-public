/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:33:13 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 18:42:53 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
// int main ()
// {
//     int arr1[5] = {1, 2, 3, 4, 5};
//     int *arr2;

//     arr2 = (int *)ft_calloc(5, sizeof(int));
//     for(int i  = 0; i < 5; i++)
//     {
//         arr2[i] = arr1[i];
//         printf("%d", arr2[i]);
//     }
//     free(arr2);
// }