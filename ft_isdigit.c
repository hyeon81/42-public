/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:36:26 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 16:24:23 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int main()
// {
//     printf("%d: %d\n", ft_isdigit('a'), isdigit('a'));
//     printf("%d: %d\n", ft_isdigit(-1), isdigit(-1));
//     printf("%d: %d\n", ft_isdigit('6'), isdigit('6'));
//     printf("%d: %d\n", ft_isdigit('1'), isdigit('1'));
//     printf("%d: %d\n", ft_isdigit('`'), isdigit('`'));
// }