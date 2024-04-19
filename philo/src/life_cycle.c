/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:19 by dabae             #+#    #+#             */
/*   Updated: 2024/04/19 15:54:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_sleep_think(t_philo *philo)
{
	if (philo->param->num_philo == 1)
		return (0);
	take_forks(philo);
	change_state(philo, EAT);
	print(philo, " is eating");
	put_down_forks(philo);
	change_state(philo, SLEEP);
	print(philo, " is sleeping");
	ft_usleep(philo->param->time_to_sleep);
	change_state(philo, THINK);
	print(philo, " is thinking");
	return (1);
}

/*check if any philopher died*/
void	*anyone_dead(void *philo)
{
	t_philo		*phi;
	uint64_t	current_time;

	phi = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&phi->lock);
		if (phi->param->stop || phi->state == DEAD)
		{
			pthread_mutex_unlock(&phi->lock);
			break;
		}
		current_time = get_time();
		if (current_time >= phi->time_limit_to_death && phi->state != EAT)
		{
			print(phi, " died");
			phi->state = DEAD;
			phi->param->stop = 1;
			pthread_mutex_unlock(&phi->lock);
			break;
		}
		pthread_mutex_unlock(&phi->lock);
		ft_usleep(1000);
	}
	return ((void *)0);
}

void	*life_start(void *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	phi->time_limit_to_death = get_time() + phi->param->time_to_die;
	if (pthread_create(&phi->thread, NULL, &anyone_dead, phi) != 0)
		return ((void *)1);
	while (phi->param->stop == 0)
		eat_sleep_think(phi);
	if (pthread_join(phi->thread, NULL) != 0)
		return ((void *)1);
	return ((void *)0);
}

void	*is_everyone_full(void *param)
{
	t_param	*data;

	data = (t_param *)param;
	pthread_mutex_lock(&data->lock);
	while (data->stop == 0 && data->num_full < data->num_philo)
	{
		pthread_mutex_unlock(&data->lock);
		ft_usleep(1000);
		pthread_mutex_lock(&data->lock);
	}

	if (data->stop == 0 && data->num_full >= data->num_philo)
	{
		pthread_mutex_lock(&data->print);
		printf("Everyone has eaten as many times as %d\n", data->num_must_eat);
		pthread_mutex_unlock(&data->print);
		data->stop = 1;
		pthread_mutex_unlock(&data->lock);
	}
	pthread_mutex_unlock(&data->lock);
	return (NULL);
}

int	life_cycle(t_param *param)
{
	pthread_t	thread;
	int			i;

	if (pthread_create(&thread, NULL, &is_everyone_full, param) != 0)
		return (1);
	i = -1;
	while (++i < param->num_philo)
	{
		if (pthread_create(&param->tids[i], NULL, &life_start,
				&param->philo[i]) != 0)
			return (1);
		ft_usleep(1);
	}
	i = -1;
	while (++i < param->num_philo)
	{
		if (pthread_join(param->tids[i], NULL) == 0)
			return (1);
	}
	if (pthread_join(thread, NULL) == 0)
		return (1);
	return (0);
}