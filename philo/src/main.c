/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:42:53 by dabae             #+#    #+#             */
/*   Updated: 2024/04/19 14:22:30 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	cleanup(t_param *param)
{
	if (param->tids)
		free(param->tids);
	if (param->tids)
		free(param->forks);
	if (param->tids)
		free(param->philo);
	free(param);
}

void	ft_exit(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->num_philo)
	{
		pthread_mutex_destroy(&param->forks[i]);
		pthread_mutex_destroy(&param->philo[i].lock);
	}
	pthread_mutex_destroy(&param->print);
	pthread_mutex_destroy(&param->lock);
	cleanup(param);
}

void	only_one_philo(t_param *param)
{
	pthread_create(&param->tids[0], NULL, &anyone_dead, &param->philo[0]);
	pthread_detach(param->tids[0]);
	while (param->stop == 0)
		ft_usleep(0);
}

int	main(int ac, char **av)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (1);
	if (ac == 5 || ac == 6)
	{
		init_param(param, av + 1);
		init_philo(param);
		if (param->num_philo == 1)
			only_one_philo(param);
		else
			life_cycle(param);
		ft_exit(param);
	}
	else
	{
		free(param);
		printf("Insufficient or too many arguments\n");
		return (1);
	}
	return (0);
}
