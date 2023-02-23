/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:03:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/23 09:57:10 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_philo *philo)
{
	while (philo->data->meals_nb == 0 || philo->eat_cont < philo->data->meals_nb)
	{
		if (philo->status == 0) // sta dormendo 
		{
			// check timestamp sul tempo morte
		}
		else if (philo->status == 1) // sta pensando
		{
			// check timpestamp sul tempo morte
			// wait till l_fork is unlock
		}
		else if (philo->status == 2) // sta ancora pensando
		{
			// check timpestamp sul tempo morte
			//  wait till r_fork is unlock
		}
		else if (philo->status == 3) // sta mangiando
		{
			// reset time_to_die
			// check timestamp on eat_time
			// eat_count++;
			// new timeval & change status to 0
		}
		else // status == 4
		{
			// philos->data->dead++;
			// return ;
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
