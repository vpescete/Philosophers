/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:52:24 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/22 10:14:38 by vpescete         ###   ########.fr       */
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

void	allocate_data(t_data *data, char **av, char ac)
{
	if (!data)
		return ; // must to handle this error 
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = ft_atoi(av[5]);
	printf("philo_num: %d\n", data->philo_num);
	printf("death_time: %llu\n", data->death_time);
	printf("eat_time: %llu\n", data->eat_time);
	printf("sleep_time: %llu\n", data->sleep_time);
	if (ac == 6)
		printf("meals_nb: %d\n", data->meals_nb);
}

void	allocate_philos(t_philo	*philos, t_data *data)
{
	if (!philos)
		return ;
	philos->data = data;
	philos->eat_cont = data->meals_nb;

}

int	handle_input(int ac, char **av)
{
	t_data	*data;
	t_philo	*philos;
	
	if (ac < 5 || ac > 6 || !(ft_atoi(av[1]) >= 0 && ft_atoi(av[1]) <= 200))
	{
		handle_input_error();
		return (0);
	}
	data = malloc(sizeof(t_data));
	allocate_data(data, av, ac);
	philos = malloc(data->philo_num * sizeof(t_philo));
	return (1);
}
