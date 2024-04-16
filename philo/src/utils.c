/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:57:53 by dabae             #+#    #+#             */
/*   Updated: 2024/04/16 16:24:49 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(uint64_t elapsed)
{
	uint64_t	start;

	start = get_time();
	while (get_time() < start + elapsed)
		usleep(100);
}

void	err_msg(char *msg)
{
	errno = 1;
	printf("%s\n", msg);
	exit(1);
}
