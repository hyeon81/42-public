/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:04:11 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/12/09 17:34:54 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_all_mutex(t_info *info, t_fork *forks, int flag, \
int idx)
{
	int	i;

	i = 0;
	if (flag == FORK)
	{
		while (i < idx)
		{
			pthread_mutex_destroy(&(forks->mutex));
			i++;
		}
	}
	if (flag == DIE || flag == PRINT || flag == ATE || flag == FORK)
		pthread_mutex_destroy(&(info->die));
	if (flag == PRINT || flag == ATE || flag == FORK)
		pthread_mutex_destroy(&(info->ate));
	if (flag == PRINT || flag == FORK)
		pthread_mutex_destroy(&(info->print));
	free(forks);
	return (DIE);
}

void	all_free(t_info *info, t_philo *philos, t_fork *forks, \
int flag)
{
	destroy_all_mutex(info, forks, FORK, info->num_of_philo);
	if (flag == FREE_PHILO)
		free(philos);
}

int	init_philo_and_fork(t_info *info, t_philo **philos, t_fork **forks)
{
	int	i;

	i = -1;
	*forks = (t_fork *)malloc(sizeof(t_fork) * info->num_of_philo);
	if (!(*forks))
		return (DIE);
	if (pthread_mutex_init(&(info->die), NULL))
		return (destroy_all_mutex(info, *forks, DIE, i));
	if (pthread_mutex_init(&(info->print), NULL))
		return (destroy_all_mutex(info, *forks, PRINT, i));
	if (pthread_mutex_init(&(info->ate), NULL))
		return (destroy_all_mutex(info, *forks, ATE, i));
	while (++i < info->num_of_philo)
	{
		if (pthread_mutex_init(&((*forks)[i].mutex), NULL))
			return (destroy_all_mutex(info, *forks, FORK, i));
		(*forks)[i].state = 0;
	}
	*philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!(*philos))
	{
		all_free(info, *philos, *forks, NO_FREE_PHILO);
		return (DIE);
	}
	return (ALIVE);
}

int	init_args(int ac, char **av, t_info *info)
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->die_flag = 0;
	info->ate_num = 0;
	info->must_eat_flag = 0;
	if (ac == 6)
	{
		info->num_must_eat = ft_atoi(av[5]);
		info->must_eat_flag = 1;
		if (info->num_must_eat <= 0)
			return (DIE);
	}
	if (info->num_of_philo <= 0 || info->time_to_die <= 0 || \
	info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (DIE);
	return (ALIVE);
}

int	start_thread(t_info *info, t_philo *philos, t_fork *forks)
{
	int	i;

	i = -1;
	gettimeofday(&(info->start_time), NULL);
	while (++i < info->num_of_philo)
	{
		philos[i].idx = i + 1;
		philos[i].eat_count = 0;
		philos[i].info = info;
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % (info->num_of_philo)];
		gettimeofday(&(philos[i].eat_time), NULL);
		if (pthread_create(&(philos[i].thread), NULL, \
		run_philo, (void *) &philos[i]))
			return (DIE);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (DIE);
	}
	return (ALIVE);
}
