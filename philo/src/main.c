/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:42:53 by dabae             #+#    #+#             */
/*   Updated: 2024/04/12 09:37:07 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_positive(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

static void	init_param(t_param *param, char **args)
{
	if (is_digit(args) && is_positive(args))
	{
		param->num_philo = args[0];
		param->time_to_die = args[1];
		param->time_to_eat = args[2];
		param->time_to_sleep = args[3];
		if (args[4])
			param->num_must_eat = args[4];
	}
	else
		return (err_msg());
}

int	main(int ac, char **av)
{
	t_param	*param;
	t_philo	*philo;
	int		i;
	int		n;

	if (ac == 5 || ac == 6)
	{
		/*Pseudo code*/
		/*
			param = malloc(sizeof(t_param));
			if (!param)
				err_msg("failed to malloc.\n");
			philo = malloc(sizeof(t_philo) * param->num_philo);
			if (!philo)
				err_msg("failed to malloc.\n");
			
			init_param(param, av);
			init_philo(philo);
			
		*/
	}
	else
}
