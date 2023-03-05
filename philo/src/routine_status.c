/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:01:12 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 18:06:47 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	status_zero(t_philo *philo)
{
	if (ft_gettimestamp(philo->start_sleep) >= philo->data->death_time)
		philo->status = 4;
	else if (ft_gettimestamp(philo->start_sleep) >= philo->data->sleep_time)
	{
		philo->prev_status = 0;
		philo->status = 5;
		return ;
	}
}

void	status_one(t_philo *philo)
{
	philo->status = 1;
	if (pthread_mutex_lock(philo->l_fork) == 0)
	{
		if (ft_gettimestamp(philo->start_sleep) >= philo->data->death_time)
		{
			philo->status = 4;
			return ;
		}
		philo->status = 2;
		return ;
	}
}

void	status_two(t_philo *philo)
{
	if (philo->data->philo_num == 1)
		philo->status = 4;
	else if (pthread_mutex_lock(philo->r_fork) == 0)
	{
		if (ft_gettimestamp(philo->start_sleep) >= philo->data->death_time)
		{
			philo->status = 4;
			return ;
		}
		philo->status = 3;
		gettimeofday(&philo->start_eat, NULL);
		return ;
	}
}

void	status_three(t_philo *philo)
{
	if (ft_gettimestamp(philo->start_eat) >= philo->data->eat_time)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo->status = 0;
		if (philo->data->meals_nb > 0)
			philo->eat_count++;
		gettimeofday(&philo->start_sleep, NULL);
		return ;
	}
}

void	routine(t_philo *philo)
{
	while (1)
	{
		if (philo->status == 0)
			status_zero(philo);
		else if (philo->status == 5)
			status_one(philo);
		else if (philo->status == 2)
			status_two(philo);
		else if (philo->status == 3)
			status_three(philo);
		else
		{
			philo->data->dead++;
			exit(0);
		}
		usleep(10);
	}
}