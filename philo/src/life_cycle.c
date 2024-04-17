/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:19 by dabae             #+#    #+#             */
/*   Updated: 2024/04/17 16:03:08 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *dead_stop(void *param)
{
	t_param	*data;
	int		i;

	i = 0;
	data = (t_param *)param;
	while (data->stop == 0)
	{
		pthread_mutex_lock(&data->philo[i % 5].lock);
		pthread_mutex_lock(&data->lock);
		if (data->philo[i % 5].time_last_meal + data->time_to_die < get_time())
		{
			data->philo[i % 5].state = DEAD;
			data->stop = 1;
			print(&data->philo[i % 5], " died\n");
		}
		else if (data->num_full >= data->num_philo)
		{
			data->stop = 1;
			pthread_mutex_lock(&data->print);
			printf("Everyone has eaten as many times as %d\n", data->num_must_eat);
			pthread_mutex_unlock(&data->print);
		}
		pthread_mutex_unlock(&data->philo[i % 5].lock);
		pthread_mutex_unlock(&data->lock);
	}
	
}

int	life_cycle(t_param *param)
{
	pthread_t thread;

	if (pthread_create(&thread, NULL, dead_stop, param) != 0)
		return (1);
	
	
}