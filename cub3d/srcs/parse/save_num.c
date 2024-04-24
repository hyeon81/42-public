/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:48:26 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/22 16:24:50 by eunjiko          ###   ########.fr       */
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
				exit_with_err("Invalid color\n");
		}
		else if (str[idx] == '\n')
			return (res);
		else
			exit_with_err("Invalid color\n");
		idx++;
	}
	return (res);
}
