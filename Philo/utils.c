/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:09:28 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/12/09 16:45:13 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_pass_time(struct timeval start)
{
	struct timeval	now;
	long long		start_time;
	long long		now_time;

	gettimeofday(&now, NULL);
	start_time = start.tv_sec * 1000000 + start.tv_usec;
	now_time = now.tv_sec * 1000000 + now.tv_usec;
	return ((now_time - start_time) / 1000);
}

int	ft_usleep(long long time, t_philo *p)
{
	struct timeval	start;
	struct timeval	now;
	long long		start_time;
	long long		now_time;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	start_time = start.tv_sec * 1000000 + start.tv_usec;
	now_time = now.tv_sec * 1000000 + now.tv_usec;
	if ((p->info->num_of_philo != 1) && check_time_to_die(p))
		return (DIE);
	while (now_time - start_time < time * 1000)
	{
		if ((p->info->num_of_philo != 1) && check_time_to_die(p))
			return (DIE);
		usleep(100);
		gettimeofday(&now, NULL);
		now_time = now.tv_sec * 1000000 + now.tv_usec;
	}
	return (ALIVE);
}

int	ft_printf(t_philo *p, int flag)
{
	if (check_time_to_die(p))
		return (DIE);
	pthread_mutex_lock(&(p->info->print));
	if (check_time_to_die(p))
	{
		pthread_mutex_unlock(&(p->info->print));
		return (DIE);
	}
	if (flag == PICK_UP_LEFT)
		printf("%lld %d %s", get_pass_time(p->info->start_time), p->idx, \
		"has taken a fork\n");
	else if (flag == PICK_UP_RIGHT)
	{
		printf("%lld %d %s%lld %d %s", get_pass_time(p->info->start_time), \
		p->idx, "has taken a fork\n", get_pass_time(p->info->start_time), \
		p->idx, "is eating\n");
	}
	else if (flag == SLEEP)
		printf("%lld %d %s", get_pass_time(p->info->start_time), p->idx, \
		"is sleeping\n");
	else if (flag == THINK)
		printf("%lld %d %s", get_pass_time(p->info->start_time), p->idx, \
		"is thinking\n");
	pthread_mutex_unlock(&(p->info->print));
	return (ALIVE);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (num * sign);
}
