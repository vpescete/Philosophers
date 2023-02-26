/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:52:24 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/26 11:15:29 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	ft_gettimestamp(t_data data)
{
	struct timeval	now;
	unsigned long	res;

	gettimeofday(&now, NULL);
	res = ((now.tv_usec / 1000) - (data.start_time.tv_usec / 1000));
	return (res);
}

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

int	check_input_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
	}
	return (1);
}

int	handle_input(int ac, char **av)
{
	t_data	data;
	
	if (ac < 5 || ac > 6 || !(ft_atoi(av[1]) >= 1 && ft_atoi(av[1]) <= 200)
		|| !check_input_int(ac, av))
	{
		handle_input_error();
		return (0);
	}
	data = allocate_data(av, ac);
	data.philos = malloc(data.philo_num * sizeof(t_philo));
	if (!data.philos)
		return (0);
	allocate_philos(data.philos, &data);
	return (1);
}
