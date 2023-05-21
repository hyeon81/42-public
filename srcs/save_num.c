/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:48:26 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/21 19:36:54 by meliesf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	save_num(const char *str)
{
	int			idx;
	long long	res;

	idx = 0;
	res = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	while (str[idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
		{
			res = res * 10 + str[idx] - '0';
			if (res > 255)
				return (exit_with_err("wrong number\n"));
		}
		else if (str[idx] == '\n')
			return(res);
		else
			return (exit_with_err("wrong number\n"));
		idx++;
	}
	return (res);
}

