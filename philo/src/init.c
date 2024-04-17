/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:42:55 by dabae             #+#    #+#             */
/*   Updated: 2024/04/17 15:50:51 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	allocate_param(t_param *param)
{
	int	i;

	i = -1;
	param->tids = malloc(sizeof(pthread_t) * param->num_philo);
	if (!param->tids)
		err_msg("failed to malloc.\n");
	param->forks = malloc(sizeof(pthread_mutex_t) * param->num_philo);
	if (!param->forks)
		err_msg("failed to malloc.\n");
	param->philo = malloc(sizeof(t_philo) * param->num_philo);
	if (!param->philo)
		err_msg("failed to malloc.\n");
	while (++i < param->num_philo)
		pthread_mutex_init(&param->forks[i], NULL);
}

/*Initializing the parameters*/
int	init_param(t_param *param, char **args)
{
	if (is_digit(args) && is_positive(args))
	{
		pthread_mutex_init(&param->print, NULL);
		pthread_mutex_init(&param->lock, NULL);
		param->stop	= 0;
		param->num_full = 0;
		param->num_philo = (int) ft_atoi(args[0]);
		param->time_to_die = (uint64_t) ft_atoi(args[1]);
		param->time_to_eat = (uint64_t) ft_atoi(args[2]);
		param->time_to_sleep = (uint64_t) ft_atoi(args[3]);
		if (args[4] && args[4] > 0)
			param->num_must_eat = (int) ft_atoi(args[4]);
		else
			param->num_must_eat = -1;
		allocate_param(param);
		return (0);
	}
	else
		err_msg("Invalid arguments. Please double-check.\n");
	return (0);
}

/*Initializing philosophers and starting the life cycle*/
int	init_philo(t_param *param)
{
	int			i;

	i = -1;
	while (++i < param->num_philo)
	{
		param->philo[i].id = i;
		param->philo[i].param = param;
		param->philo[i].left_fork = &param->forks[i];
		if (i != 0)
			param->philo[i].right_fork = &param->forks[i - 1];
		else
			param->philo[0].right_fork = &param->forks[param->num_philo - i];
		param->philo[i].num_eat = 0;
		param->philo[i].state = -1;
		param->philo[i].time_last_meal = 0;
		param->philo[i].thread = param->tids[i];
		pthread_mutex_init(&(param->philo[i].lock), NULL);
	}
	i = -1;
    while (++i < param->num_philo)
    {
		if (pthread_join(param->tids[i], NULL) != 0)
			return (-1);
	}
	return (0);
}
