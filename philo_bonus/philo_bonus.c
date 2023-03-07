/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 17:58:39 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	run_parent_process(t_data *data)
{
	int	count_m;
	int	status;
	
	count_m = 0;
	while (waitpid(0, &status, 0))
	{
		if (((status >> 8) & 0x0000000ff) == 0)
		{
			kill(0, SIGKILL);
			break ;
		}
		if (((status >> 8) & 0x0000000ff) == 1)
		{
			count_m++;
			if (count_m == data->philo_num)
				break ;
		}
	}
}

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
	// printf("ciao sono tua madre\n");
	run_parent_process(data);
	return (0);
}
