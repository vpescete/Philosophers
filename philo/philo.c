/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:03:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 18:31:24 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_execute(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->l_fork = &philo->data->forks[philo->id];
	if (philo->id == philo->data->philo_num - 1)
		philo->r_fork = &philo->data->forks[0];
	else
		philo->r_fork = &philo->data->forks[philo->id + 1];
	routine(philo);
	return (0);
}

int	checker(t_philo *philo, int i)
{
	if (philo[i].data->meals_nb != 0 && philo[i].eat_count >= philo[i].data->meals_nb)
		return (0);
	if (philo[i].prev_status != philo[i].status)
	{
		if (philo[i].status == 0)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, SLEEP);
			philo[i].prev_status = 0;
		}
		if (philo[i].status == 5)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, THINK);			
			philo[i].prev_status = 5;
		}
		else if (philo[i].status == 1)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, FORK);
			philo[i].prev_status = 1;
		}
		else if (philo[i].status == 2)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, FORK);
			philo[i].prev_status = 2;
		}
		else if (philo[i].status == 3)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, EAT);
			philo[i].prev_status = 3;
		}
		else if (philo[i].status == 4)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, DEAD);
			return(0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = handle_input(ac, av);
	if (!data)
		return (0);
	while (1)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			usleep(10);
			if (!checker(data->philos, i))
				exit(0);
		}
	}	
	return (0);
}
