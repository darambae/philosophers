/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:42:53 by dabae             #+#    #+#             */
/*   Updated: 2024/04/16 16:33:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



int	main(int ac, char **av)
{
	t_param	*param;
	t_philo	**philo;
	int		i;
	int		n;

	if (ac == 5 || ac == 6)
	{
		init_param(param, av);
		init_philo(philo, param);
	}
	else
		err_msg("Insufficient or too many arguments\n");
}
