/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:49:24 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/17 18:52:51 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_err(char	*str)
{
	write(2, str, ft_strlen(str));
	return (-1);
	exit(-1);
}

int	exit_with_err(char	*str)
{
	write(2, str, ft_strlen(str));
	exit(-1);
}
