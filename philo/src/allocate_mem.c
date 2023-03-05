/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:18:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 18:15:39 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*allocate_data(char **av, char ac)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = ft_atoi(av[5]);
	// printf("philo_num: %d\n", data->philo_num);
	// printf("death_time: %llu\n", data->death_time);
	// printf("eat_time: %llu\n", data->eat_time);
	// printf("sleep_time: %llu\n", data->sleep_time);
	// if (ac == 6)
	// 	printf("meals_nb: %d\n", data->meals_nb);
	data->forks = malloc(data->philo_num * sizeof(pthread_mutex_t));
	gettimeofday(&data->start_time, NULL);
	return (data);
}

void	allocate_philos(t_philo	*philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		philos[i].data = data;
		philos[i].id = i;
		pthread_mutex_init(data->forks + i, NULL);
		philos[i].status = 5;
		philos[i].prev_status = 5;
		philos[i].eat_count = 0;
		gettimeofday(&philos[i].start_sleep, NULL);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		philos[i].l_fork = data->forks + i;
		if (i == data->philo_num - 1)
			philos[i].r_fork = data->forks;
		else
			philos[i].r_fork = (data->forks + i + 1);
		// usleep(1000);
		pthread_create(&philos[i].t1, NULL, &start_execute, &philos[i]);
		i++;
	}
	usleep(10);
	i = 0;
	while (++i < data->philo_num)
	{
		philos[i].l_fork = data->forks + i;
		if (i == data->philo_num - 1)
			philos[i].r_fork = data->forks;
		else
			philos[i].r_fork = (data->forks + i + 1);
		// usleep(1000);
		pthread_create(&philos[i].t1, NULL, &start_execute, &philos[i]);
		i++;
	}
}
