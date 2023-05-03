/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:32:12 by eunjiko           #+#    #+#             */
/*   Updated: 2022/09/12 03:09:16 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	long	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	num = (long)n;
	len = num_len(num);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	else if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}
