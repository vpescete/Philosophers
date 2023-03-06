/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:01:27 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/06 16:39:07 by vpescete         ###   ########.fr       */
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
	if (data->death_time < 60 || data->sleep_time < 60 || data->eat_time < 60)
	{
		handle_input_error();
		return (NULL);
	}
	return (data);
}
