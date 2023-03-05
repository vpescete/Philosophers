/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:52:24 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 16:04:57 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

t_data	*handle_input(int ac, char **av)
{
	t_data	*data;
	
	if (ac < 5 || ac > 6 || !(ft_atoi(av[1]) >= 1 && ft_atoi(av[1]) <= 200)
		|| !check_input_int(ac, av))
	{
		handle_input_error();
		return (NULL);
	}
	data = allocate_data(av, ac);
	data->philos = malloc(data->philo_num * sizeof(t_philo));
	data->dead = 0;
	if (!data->philos)
		return (NULL);
	allocate_philos(data->philos, data);
	// printf("sono qui!\n");
	return (data);
}
