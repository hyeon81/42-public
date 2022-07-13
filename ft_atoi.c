/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:05 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 18:25:19 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;
	int					sign;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{	
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

// int main()
// {
// 	char *str1 = "1234abcde";
// 	char *str2 = "-1234a";	
// 	char *str3 = "-+1234ab";
// 	char *str4 = "+12345ab";
// 	char *str5 = "   12345ab";
// 	char *str6 = "ab";

// 	printf("%d : %d\n", ft_atoi(str1), atoi(str1));	
// 	printf("%d : %d\n", ft_atoi(str2), atoi(str2));	
// 	printf("%d : %d\n", ft_atoi(str3), atoi(str3));	
// 	printf("%d : %d\n", ft_atoi(str4), atoi(str4));	
// 	printf("%d : %d\n", ft_atoi(str5), atoi(str5));	
// 	printf("%d : %d\n", ft_atoi(str6), atoi(str6));	
// 	printf("%d : %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
// }
