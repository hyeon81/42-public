/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:37:09 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:39 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;
	t_fork	*forks;
	t_info	info;

	if (ac != 6 && ac != 5)
		return (DIE);
	if (init_args(ac, av, &info))
		return (DIE);
	if (init_philo_and_fork(&info, &philos, &forks))
		return (DIE);
	start_thread(&info, philos, forks);
	all_free(&info, philos, forks, FREE_PHILO);
	return (0);
}
