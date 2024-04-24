/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:56:07 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/12/09 17:31:03 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef enum philo_enum{
	ALIVE,
	DIE,
	PICK_UP,
	EAT,
	SLEEP,
	THINK,
	FREE_PHILO,
	NO_FREE_PHILO,
	PICK_UP_LEFT,
	PICK_UP_RIGHT,
	FORK,
	ATE,
	PRINT,
}t_philo_enum;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				state;
}t_fork;

typedef struct s_info
{
	pthread_mutex_t	die;
	pthread_mutex_t	ate;
	pthread_mutex_t	print;
	struct timeval	start_time;
	int				num_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				num_must_eat;
	int				ate_num;
	int				die_flag;
	int				must_eat_flag;
}t_info;

typedef struct s_philo
{
	pthread_t		thread;
	t_info			*info;
	struct timeval	eat_time;
	int				idx;
	int				eat_count;
	t_fork			*l_fork;
	t_fork			*r_fork;
}t_philo;

/* init.c */
int			destroy_all_mutex(t_info *info, t_fork *forks, int flag, \
int idx);
void		all_free(t_info *info, t_philo *philos, t_fork *forks, \
int flag);
int			init_philo_and_fork(t_info *info, t_philo **philos, t_fork **forks);
int			init_args(int ac, char **av, t_info *info);
int			start_thread(t_info *info, t_philo *philos, t_fork *forks);

/* run_philo.c */
int			pick_up(t_philo *p, t_fork	*fork, int flag);
void		put_down(t_philo *p);
int			eating(t_philo *p);
int			sleeping_and_thinking(t_philo *p);
void		*run_philo(void *philo);

/* check_die */
int			check_eat_count(t_philo *p);
int			check_time_to_die(t_philo *p);

/* utils */
long long	get_pass_time(struct timeval start);
int			ft_usleep(long long time, t_philo *p);
int			ft_printf(t_philo *p, int flag);
long long	ft_atoi(const char *str);

#endif
