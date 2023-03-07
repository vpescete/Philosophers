/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:24:40 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 12:10:34 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo_bonus.h"

void	status_zero(t_data *data)
{
	if (ft_gettimestamp(data->philo.start_sleep) >= data->death_time)
	{
		// ft_close(data);
	}
	if (ft_gettimestamp(data->philo.start_sleep) >= data->sleep_time)
		status_one(data);
}

void	status_one(t_data *data)
{
	if (ft_gettimestamp(data->philo.start_sleep) >= data->death_time)
	{
		// ft_close(data);
	}
	if (sem_wait(data->sem) && sem_wait(data->print))
	{
		printf("%d %d %s\n", gettimeofday(&data->start_time, NULL),
					data->philo.id, FORK);
		sem_post(data->print);
	}
	status_two(data);
}

void	status_two(t_data *data)
{
	if (ft_gettimestamp(data->philo.start_sleep) >= data->death_time)
	{
		// ft_close(data);
	}
	if (sem_wait(data->sem) && sem_wait(data->print))
	{
		printf("%d %d %s\n", gettimeofday(&data->start_time, NULL),
				data->philo.id, FORK);
		printf("%d %d %s\n", gettimeofday(&data->start_time, NULL),
				data->philo.id, EAT);
		sem_post(data->print);
	}
	gettimeofday(&data->philo.start_eat, NULL);
	status_three(data);
}

void	status_three(t_data *data)
{
	if (ft_gettimestamp(data->philo.start_eat) >= data->eat_time)
	{
		data->philo.eat_count++;
		if (data->philo.eat_count == data->meals_nb)
		{
			data->philo.status = 10;
			return ;
		}
		sem_post(data->sem);
		sem_post(data->sem);
		if (sem_wait(data->print))
		{
			printf("%d %d %s\n", gettimeofday(&data->start_time, NULL),
						data->philo.id, SLEEP);
			sem_post(data->print);
		}
		gettimeofday(&data->philo.start_sleep, NULL);
		status_one(data);
	}
}

void	execute_child(t_data *data)
{	
	data->philo.eat_count = 0;
	data->philo.status = 1;
	gettimeofday(&data->philo.start_sleep, NULL);
	while(1)
	{
		if (data->philo.status == 1)
			status_one(data);
		else if (data->philo.status == 3)
			status_three(data);
		else if (data->philo.status == 10)
			break ;	
	}
	// send_sign(data);
}
