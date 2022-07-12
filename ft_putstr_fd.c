/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:05:23 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/06 14:18:32 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	int i;
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