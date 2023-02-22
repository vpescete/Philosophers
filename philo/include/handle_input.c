/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:52:24 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/21 19:44:41 by vpescete         ###   ########.fr       */
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

void	handle_input_error(void)
{
	printf("\n\033[0;31mWRONG INPUT\033[0m\n\n");
	printf("\tRIGHT INPUT:	[number_of_philosophers]");
	printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
	printf(" (optional)[number_of_times_each_philosopher_must_eat]\n\n");
	printf("\t\e[4mAll the arguments has to be integers. the 2nd, ");
	printf("3th and 4th are consider in milliseconds\e[24m\n\n");
}

int	handle_input(int ac, char **av)
{
	t_data	*data;
	
	if (ac < 5 || ac > 6)
	{
		handle_input_error();
		return (0);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = ft_atoi(av[5]);
	return (1);
}
