/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:01:27 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 10:05:23 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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

void	handle_input_error(void)
{
	printf("\n\033[0;31mWRONG INPUT\033[0m\n\n");
	printf("\tRIGHT INPUT:\t\033[0;32m./philo\t[number_of_philosophers]");
	printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
	printf(" (optional)[number_of_times_each_philosopher_must_eat]\033[0m\n\n");
	printf("\t\e[4mAll the arguments has to be integers. the 2nd, ");
	printf("3th and 4th are considered in milliseconds\e[24m\n\n");
}
