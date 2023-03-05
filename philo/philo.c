/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:03:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 22:59:56 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_execute(void *data)
{
	t_philo	*philo;

	
	philo = (t_philo *)data;
	// printf("id: %i	addr l_fork: %p\n", philo[i].id, philo->l_fork);
	// printf("id: %i	addr r_fork: %p\n", philo->id, philo->r_fork);
	// usleep(100);
	while (!philo->data->checker_is_run)
		continue;
	if (philo->id % 2 == 0)
		usleep(1000);
	routine(philo);
	return (0);
}

int	checker(t_philo *philo, int i)
{
	if (philo[i].data->meals_nb != 0 && philo[i].eat_count >= philo[i].data->meals_nb)
		return (0);
	if (ft_gettimestamp(philo[i].start_sleep) > philo[i].data->death_time)
		philo[i].status = 4;
	if (philo[i].prev_status != philo[i].status)
	{
		if (philo[i].status == 0)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, SLEEP);
			philo[i].prev_status = 0;
		}
		else if (philo[i].status == 5)
		{
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, THINK);			
			philo[i].prev_status = 5;
		}
		else if (philo[i].status == 1)
		{
			printf("%lu %d l_%s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, FORK);
			philo[i].prev_status = 1;
		}
		else if (philo[i].status == 2)
		{
			printf("%lu %d r_%s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, FORK);
			printf("%lu %d %s\n", ft_gettimestamp(philo[i].data->start_time),
					philo[i].id, EAT);
			philo[i].prev_status = 2;
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
	data->checker_is_run = 1;
	while (1)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			if (!checker(data->philos, i))
				return (0);
		}
	}	
	return (0);
}
