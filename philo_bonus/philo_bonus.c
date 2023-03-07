/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 12:06:44 by vpescete         ###   ########.fr       */
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
	i = -1;
	while (++i < data->philo_num)
	{
		if ((parent = fork()) == 0)
		{
			data->philo.id = i;
			break ;
		}
	}
	execute_child(data);
	return (0);
}
