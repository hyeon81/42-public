/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:05:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 14:29:38 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main ()
// {
//     ft_putstr_fd("abcded", 1);
// }