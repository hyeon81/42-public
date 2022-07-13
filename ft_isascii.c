/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:33:30 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 16:23:51 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int main()
// {
//     printf("%d: %d\n", ft_isascii('a'), isascii('a'));
//     printf("%d: %d\n", ft_isascii(-1), isascii(-1));
//     printf("%d: %d\n", ft_isascii(256), isascii(256));
//     printf("%d: %d\n", ft_isascii('1'), isascii('1'));
//     printf("%d: %d\n", ft_isascii('`'), isascii('`'));
// }