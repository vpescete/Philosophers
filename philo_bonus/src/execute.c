/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:24:40 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 18:45:49 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	status_zero(t_data *data)
{
	check_if_is_dead(data);
	if (ft_gettimestamp(data->philo.start_sleep) >= data->sleep_time)
	{
		data->philo.status = 1;
		status_one(data);
	}
}

void	status_one(t_data *data)
{
	sem_wait(data->print);
	printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
		data->philo.id, THINK);
	sem_post(data->print);
	check_if_is_dead(data);
	sem_wait(data->sem);
	sem_wait(data->print);
	printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
		data->philo.id, FORK);
	sem_post(data->print);
	check_if_is_dead(data);
	data->philo.status = 2;
	status_two(data);
}

void	status_two(t_data *data)
{
	if (data->philo_num == 1)
	{
		sem_wait(data->print);
		printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
			data->philo.id, DEAD);
		if (data->philo.status == 3)
			sem_post(data->sem);
		sem_post(data->sem);
		exit(0);
	}
	check_if_is_dead(data);
	sem_wait(data->sem);
	sem_wait(data->print);
	printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
		data->philo.id, FORK);
	printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
		data->philo.id, EAT);
	sem_post(data->print);
	check_if_is_dead(data);
	gettimeofday(&data->philo.start_eat, NULL);
	data->philo.status = 3;
	status_three(data);
}

void	status_three(t_data *data)
{
	check_if_is_dead(data);
	if (ft_gettimestamp(data->philo.start_eat) >= data->eat_time)
	{
		data->philo.eat_count++;
		if (data->philo.eat_count == data->meals_nb)
		{
			sem_post(data->sem);
			sem_post(data->sem);
			sem_unlink("/forks");
			sem_unlink("/print");
			sem_close(data->sem);
			sem_close(data->print);
			exit(1);
		}
		sem_post(data->sem);
		sem_post(data->sem);
		sem_wait(data->print);
		printf("%lu %d %s\n", ft_gettimestamp(data->start_time),
			data->philo.id, SLEEP);
		sem_post(data->print);
		gettimeofday(&data->philo.start_sleep, NULL);
		data->philo.status = 0;
		status_zero(data);
	}
}

void	execute_child(t_data *data)
{	
	data->philo.eat_count = 0;
	data->philo.status = 1;
	gettimeofday(&data->philo.start_sleep, NULL);
	gettimeofday(&data->start_time, NULL);
	while (1)
	{
		if (data->philo.status == 0)
			status_zero(data);
		else if (data->philo.status == 1)
			status_one(data);
		else if (data->philo.status == 3)
			status_three(data);
	}
}
