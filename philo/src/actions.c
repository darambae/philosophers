/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:48:17 by dabae             #+#    #+#             */
/*   Updated: 2024/04/17 15:50:34 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->param->print);
	printf("%lu %d %s\n", get_time(), philo->id, str);
	pthread_mutex_unlock(&philo->param->print);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
    print(philo, " has taken a fork\n");
    philo->state = EAT;
    ft_usleep(philo->param->time_to_eat);
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
    philo->num_eat++;
    if (philo->num_eat == philo->param->num_must_eat)
    {
		philo->param->num_full++;
    }
    philo->time_last_meal = get_time();
}

void	*eat(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	take_forks(philo);
    print(philo, " is eating\n");
    put_down_forks(philo);
    philo->state = SLEEP;
    print(philo, " is sleeping\n");
    ft_usleep(philo->param->time_to_sleep);
    philo->state = THINK;
    print(philo, " is thinking\n");
}