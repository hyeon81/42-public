/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:43:01 by eunjiko           #+#    #+#             */
/*   Updated: 2023/04/05 22:28:37 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			idx;
	long long	sign;
	long long	res;

	idx = 0;
	sign = 1;
	res = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		if (res < 0)
			return ((sign + 1) / -2);
		idx++;
	}
	return ((int)(res * sign));
}
