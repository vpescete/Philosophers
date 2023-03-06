/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:03:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/06 12:04:20 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_execute(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->data->checker_is_run)
		continue ;
	if (philo->id % 2 == 0)
		usleep(1000);
	routine(philo);
	return (0);
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
	ft_close(data);
	return (0);
}
