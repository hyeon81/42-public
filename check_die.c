/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:53:25 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/12/09 16:53:26 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat_count(t_philo *p)
{
	p->eat_count++;
	if (check_time_to_die(p))
		return (DIE);
	pthread_mutex_lock(&(p->info->ate));
	if (p->eat_count == p->info->num_must_eat)
		p->info->ate_num++;
	if (p->info->num_of_philo == p->info->ate_num)
	{
		pthread_mutex_unlock(&(p->info->ate));
		pthread_mutex_lock(&(p->info->die));
		p->info->die_flag = 1;
		pthread_mutex_unlock(&(p->info->die));
		return (DIE);
	}
	pthread_mutex_unlock(&(p->info->ate));
	return (ALIVE);
}

int	check_time_to_die(t_philo *p)
{
	pthread_mutex_lock(&(p->info->die));
	if (p->info->die_flag >= 1)
	{
		pthread_mutex_unlock(&(p->info->die));
		return (DIE);
	}
	else if (get_pass_time(p->eat_time) >= p->info->time_to_die)
	{
		p->info->die_flag = 1;
		pthread_mutex_unlock(&(p->info->die));
		printf("%lld %d is died\n", get_pass_time(p->info->start_time), p->idx);
		return (DIE);
	}
	pthread_mutex_unlock(&(p->info->die));
	return (ALIVE);
}
