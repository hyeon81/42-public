/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:49:24 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/26 15:32:04 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_with_err(char	*str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(-1);
}