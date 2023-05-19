/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:48:26 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/17 00:53:17 by meliesf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	ft_atoi(const char *str)
// {
// 	int			idx;
// 	long long	sign;
// 	long long	res;

// 	idx = 0;
// 	sign = 1;
// 	res = 0;
// 	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
// 		idx++;
// 	if (str[idx] == '+' || str[idx] == '-')
// 		return (-1);
// 	while (str[idx] >= '0' && str[idx] <= '9')
// 	{
// 		res = res * 10 + str[idx] - '0';
// 		if (res < 0 || res > 255) //0이상 225이하
// 			return (-1);
// 		idx++;
// 	}
// 	return ((int)(res * sign));
// }

int	ft_atoi(const char *str)
{
	int			idx;
	long long	res;

	idx = 0;
	res = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
		return (-1);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		if (res > 255) //0이상 225이하 
			return (-1);
		idx++;
	}
	return (res);
}

