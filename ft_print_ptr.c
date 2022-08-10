/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:43 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/08/10 17:19:44 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_addr(unsigned long long n, int *res)
{
	int		c;
    char    *hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		c = n % 16;
		ft_print_addr(n / 16, res);
		write (1, &hex[c], 1);
		(*res)++;
	}
	else
	{
		write (1, &hex[n], 1);
		(*res)++;
	}
}

void ft_print_ptr(void *ptr, int *res)
{
	unsigned long long addr;
    addr = (unsigned long long)ptr;

	if (addr == 0)
	{
		write(1, "0x0", 3);
		*res += 3;
		return ;
	}
	write(1, "0x", 2);
	*res += 2;
	ft_print_addr(addr, res);
}

// int main()
// {
// 	int res = 0;
// 	int a = 1;
// 	ft_print_ptr(&a, &res);
// 	printf("\n res: %d", res);
// 	printf("\n ret: %d", printf("\n ret: %p", &a));
// }