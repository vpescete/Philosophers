/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:18:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 22:39:40 by vpescete         ###   ########.fr       */
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
	else
		data->meals_nb = 0;
	data->checker_is_run = 0;
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
		// printf("addr fork: %p\n", data->forks + i);
		philos[i].status = 5;
		philos[i].prev_status = 0;
		philos[i].eat_count = 0;
		gettimeofday(&philos[i].start_sleep, NULL);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		philos[i].l_fork = data->forks + i;
		// printf("id: %i	addr l_fork: %p\n", philos[i].id, philos[i].l_fork);
		if (i == data->philo_num - 1)
			philos[i].r_fork = data->forks;
		else
			philos[i].r_fork = (data->forks + i + 1);
		// printf("id: %i	addr r_fork: %p\n", philos[i].id, philos[i].r_fork);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_create(&philos[i].t1, NULL, &start_execute, philos + i);
}
