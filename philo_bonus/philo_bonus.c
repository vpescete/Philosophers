/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 16:31:55 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = handle_input(ac, av);
	sem_initialize(data);
	i = -1;
	while (++i < data->philo_num)
	{
		data->parent = fork();
		if (data->parent == 0)
		{
			data->philo.id = i;
			break ;
		}
	}
	if (data->parent == 0)
		execute_child(data);
	printf("ciao sono tua madre\n");
	while (1)
	{
	}
	return (0);
}
