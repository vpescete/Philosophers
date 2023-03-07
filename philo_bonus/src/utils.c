/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:12:07 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 18:45:57 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_atoi(char *s)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += *s - 48;
		s++;
	}
	return (value * sign);
}

unsigned long	ft_gettimestamp(struct timeval goddog)
{
	struct timeval	now;
	unsigned long	res;

	gettimeofday(&now, NULL);
	res = (((now.tv_sec * 1000) + (now.tv_usec / 1000))
			- ((goddog.tv_sec * 1000) + (goddog.tv_usec / 1000)));
	return (res);
}

void	check_if_is_dead(t_data *data)
{
	if (ft_gettimestamp(data->philo.start_sleep) >= data->death_time)
	{
		sem_wait(data->print);
		printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
			data->philo.id, DEAD);
		if (data->philo.status == 3)
			sem_post(data->sem);
		sem_post(data->sem);
		exit(0);
	}
}
