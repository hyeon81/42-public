/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:07:40 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/12/09 16:57:24 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up(t_philo *p, t_fork	*fork, int flag)
{
	if (check_time_to_die(p))
		return (DIE);
	while (1)
	{
		pthread_mutex_lock(&(fork->mutex));
		if (fork->state == 0)
		{
			fork->state = 1;
			pthread_mutex_unlock(&(fork->mutex));
			if (ft_printf(p, flag))
				return (DIE);
			return (ALIVE);
		}
		pthread_mutex_unlock(&(fork->mutex));
		usleep(100);
		if (check_time_to_die(p))
			return (DIE);
	}
}

void	put_down(t_philo *p)
{
	pthread_mutex_lock(&(p->r_fork->mutex));
	p->r_fork->state = 0;
	pthread_mutex_unlock(&(p->r_fork->mutex));
	pthread_mutex_lock(&(p->l_fork->mutex));
	p->l_fork->state = 0;
	pthread_mutex_unlock(&(p->l_fork->mutex));
}

int	eating(t_philo *p)
{
	if (pick_up(p, p->l_fork, PICK_UP_LEFT) == ALIVE)
	{
		if (pick_up(p, p->r_fork, PICK_UP_RIGHT))
			return (DIE);
		gettimeofday(&(p->eat_time), NULL);
	}
	else
		return (DIE);
	if (p->info->must_eat_flag == 1 && check_eat_count(p))
		return (DIE);
	if (ft_usleep(p->info->time_to_eat, p))
		return (DIE);
	put_down(p);
	return (ALIVE);
}

int	sleeping_and_thinking(t_philo *p)
{	
	if (ft_printf(p, SLEEP))
		return (DIE);
	if (ft_usleep(p->info->time_to_sleep, p))
		return (DIE);
	if (ft_printf(p, THINK))
		return (DIE);
	return (ALIVE);
}

void	*run_philo(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->info->num_of_philo == 1)
	{
		printf("%lld %d has taken a fork\n", get_pass_time(p->info->start_time), \
		1);
		ft_usleep(p->info->time_to_die, p);
		printf("%lld %d is died\n", get_pass_time(p->info->start_time), 1);
		return (p);
	}
	if (p->idx % 2 == 0)
	{
		while (get_pass_time(p->info->start_time) < p->info->time_to_eat)
			usleep(100);
	}
	while (1)
	{
		if (eating(p))
			return (p);
		if (sleeping_and_thinking(p))
			return (p);
	}
}
