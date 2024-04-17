/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:19 by dabae             #+#    #+#             */
/*   Updated: 2024/04/17 14:37:18 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *dead_stop(void *param)
{
	t_param	*data;
	int		i;

	i = -1;
	data = (t_param *)param;
	while (data->stop == 0)
	{
		while (++i < data->num_philo)
		pthread_mutex_lock(&data->philo[i].lock);
		pthread_mutex_lock(&data->lock);
		if (data->philo[i].time_last_meal + data->time_to_die < get_time())
		{
			data->philo[i].state = DEAD;
			data->stop = 1;
			print(&data->philo[i], " died\n");
		}
		if (data->philo[i].num_eat == data->num_must_eat)
		{
			data->philo[i].state = FULL;
		}
		pthread_mutex_unlock(&data->philo[i].lock);
		pthread_mutex_unlock(&data->lock);
	}
	
}

int	life_cycle(t_philo **philo, t_param *param)
{
	pthread_t thread;

	if (pthread_create(&thread, NULL, dead_stop, param) != 0)
		return (1);
	
	
}