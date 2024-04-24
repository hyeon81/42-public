/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:33:25 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 16:22:41 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int main()
// {
//     printf("%d: %d\n", ft_isalpha('a'), isalpha('a'));
//     printf("%d: %d\n", ft_isalpha('B'), isalpha('B'));
//     printf("%d: %d\n", ft_isalpha('1'), isalpha('1'));
//     printf("%d: %d\n", ft_isalpha('`'), isalpha('`'));
// }