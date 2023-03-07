/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 12:37:13 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;
	pid_t	parent;

	data = handle_input(ac, av);
	sem_initialize(data);
	parent = fork();
	i = -1;
	while (++i < data->philo_num)
	{
		if (parent == 0)
		{
			data->philo.id = i;
			break ;
		}
	}
	while(1);
	return (0);
}
