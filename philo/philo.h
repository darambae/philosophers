/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:41:34 by dabae             #+#    #+#             */
/*   Updated: 2024/04/16 16:34:31 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/time.h>
# include <errno.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define FORK 3
# define DEAD 4
# define STOP 5


typedef struct s_param
{
	int				num_philo;
	int				num_must_eat;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	pthread_t		*tids;

	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
	pthread_mutex_t	stop;
}				t_param;

typedef struct s_philo
{
	int				id;
	int				state;
	uint64_t		time_last_meal;
	int				num_eat;
	pthread_t		thread;

	pthread_mutex_t	lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_param			*param;
}					t_philo;

int			is_digit(char **args);
long		ft_atoi(char *str);
void		ft_usleep(uint64_t elapsed);
void		err_msg(char *msg);
uint64_t	get_time(void);


void		*life_cycle(void *philo);
void		*take_forks(t_philo *philo);
void		*put_down_forks(t_philo *philo);
void		*eat(void *arg);
int			*dead_stop(void *philo);
void		print(t_philo *philo, char *str);

#endif
