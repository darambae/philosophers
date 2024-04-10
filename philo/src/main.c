/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:42:53 by dabae             #+#    #+#             */
/*   Updated: 2024/04/10 16:25:02 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_param(t_param *param, char **args)
{
	param->num_philo = args[0];
	param->time_to_die = args[1];
	param->time_to_eat = args[2];
	param->time_to_sleep = args[3];
	if (args[4])
		param->num_must_eat = args[4];
}

void	*eat(void *arg)
{
	int		i;
	int		time_stamp;

	time_stamp = gettimeofday();
	i = (int *)arg;
	printf("%d : philo %d is eating\n", time_stamp, i);
}

int	main(int ac, char **av)
{
	t_param			*param;
    pthread_t		philo[param->num_philo];
	pthread_mutex_t	forks[param->num_philo];
	int				i;
	int 			n;

	param = malloc(sizeof(t_param));
	if (ac == 5 || ac == 6)
	{
		set_param(param, av + 1);
		i = 0;
		n = 2 * i;
		while (n < param->num_must_eat)
		{
			pthread_create(&philo[n], NULL, eat, &n);
			i++;
		}
		i = 0;
		while (n < param->num_must_eat)
		{
			pthread_join(philo[n], NULL);
			i++;
		}
	}
	else
}
