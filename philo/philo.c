/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:03:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/02 14:21:58 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_gettimestamp(t_data *data)
{
	struct timeval	now;
	unsigned long	res;

	gettimeofday(&now, NULL);
	res = ((now.tv_usec / 1000) - (data->start_time.tv_usec / 1000));
	return (res);
}

void	status_zero(t_philo *philo)
{
	// we check if the actual timestamp less the one that we calculate at the begging is less than the time to die
	// 	in this case we change status to 4
	if (ft_gettimestamp(philo->data) >= philo->data->death_time)
	{
		philo->status = 4;
		ft_close(philo);
	}
	else if (ft_gettimestamp(philo->data) < philo->data->death_time)
	{
		philo->ttd += ft_gettimestamp(philo->data);
		if (philo->ttd == philo	->data->sleep_time)
		{
			philo->status = 1;
			return ;
		}
	}
	// otherwise we wait till the time_sleep
	// if we reach the time_sleep, then we change status to 1
}

void	status_one(t_philo *philo)
{
	// we check if the timestamp is greater than the time to die
	// 	in this case we change status to 4
	if (ft_gettimestamp(philo->data) >= philo->data->death_time)
	{
		philo->status = 4;
		return ;
	}
	else if (pthread_mutex_lock(&philo->l_fork) == 1)
	{
		pthread_mutex_lock(&philo->l_fork);
		philo->status = 2;
		return ;
	}
	else
	{
		philo->ttd	+= ft_gettimestamp(philo->data);
		usleep(10);
	}
	// otherwise we wait till l_fork is unlock
	// in case that we lock the l_fork, then we change status to 2
}

void	status_two(t_philo *philo)
{
	// we check if the timestamp is less than the time to die
	// 	in this case we change status to 4
	if (ft_gettimestamp(philo->data) >= philo->data->death_time)
	{
		philo->status = 4;
		return ;
	}
	else if (pthread_mutex_lock(&philo->r_fork) == 1)
	{
		pthread_mutex_lock(&philo->r_fork);
		philo->status = 3;
		return ;
	}
	else
	{
		philo->ttd	+= ft_gettimestamp(philo->data);
		usleep(10);
	}

	//  wait till r_fork is unlock
	// in case that we lock the r_fork, then we change status to 3
	// otherwise we wait till r_fork is unlock
}

void	status_three(t_philo *philo)
{
	// reset time_to_die
	philo->ttd = 0;
	if (ft_gettimestamp(philo->data) >= philo->data->eat_time)
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		philo->status = 0;
		// philo-> = ft_gettimestamp(philo->data);
		if (philo->data->meals_nb > 0)
			philo->eat_cont++;
		return ;
	}
	
	// we must eat until we reach the eat_time
	// eat_count++;
	// new timeval & change status to 0
}


void	routine(t_philo *philo)
{
	while (philo->data->meals_nb == 0 || philo->eat_cont < philo->data->meals_nb)
	{
		if (philo->status == 0)
		{
			status_zero(philo);
		}
		else if (philo->status == 1) // sta pensando
		{
			status_one(philo);
		}
		else if (philo->status == 2) // sta ancora pensando
		{
			status_two(philo);
		}
		else if (philo->status == 3) // sta mangiando
		{
			status_three(philo);
		}
		else // status == 4
		{
			philo->data->dead++;
			return ;
		}
	}	
}

void	*start_execute(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	philo->l_fork = philo->data->forks[philo->id];
	if (philo->id == philo->data->philo_num - 1)
		philo->r_fork = philo->data->forks[0];
	else
		philo->r_fork = philo->data->forks[philo->id + 1];
	while (philo->data->dead != 0 && philo->data->finished != 0)
		routine(philo);
	return(0);
}

int main(int ac, char **av)
{
	if (handle_input(ac, av) == 0)
		return (0);
	return (0);
}
