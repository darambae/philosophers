/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:42:53 by dabae             #+#    #+#             */
/*   Updated: 2024/04/17 14:59:50 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int	main(int ac, char **av)
{
	t_param	*param;
	int		i;
	int		n;

	if (ac == 5 || ac == 6)
	{
		init_param(param, av);
		init_philo(param);
		life_cycle(param);
	}
	else
		err_msg("Insufficient or too many arguments\n");
}
