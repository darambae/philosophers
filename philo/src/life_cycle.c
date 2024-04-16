/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:19 by dabae             #+#    #+#             */
/*   Updated: 2024/04/16 16:41:14 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	*dead_stop(void *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	if (phi->time_last_meal + phi->param->time_to_die < get_time())
	{
		pthread_mutex_lock(&phi->param->dead);
		phi->state = DEAD;
		print(phi, " died\n");
		pthread_mutex_unlock(&phi->param->dead);
		return (0);
	}
	if (phi->num_eat == phi->param->num_must_eat)
	{
		pthread_mutex_lock(&phi->param->stop);
		phi->state = STOP;
		print(phi, " everyone has eaten enough\n");
		pthread_mutex_unlock(&phi->param->stop);
		return (0);
	}
	return (1);
}

void	*life_cycle(void *philo)
{
	pthread_t	*phi;
	pthread_t	thread;

	phi = (t_philo *)philo;
	while (dead_stop(phi) != 0)
		pthread_create(&thread, NULL, eat, phi);
}