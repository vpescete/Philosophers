/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 10:04:00 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*sem_init(t_data *data)
{
	char	*name;
	sem_t	*sem;
	
	name = "/forks";
	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0666, data->philo_num);
	return (sem);
}

void	execute_child(t_data *data)
{	
	data->philo.eat_count = 0;
	data->philo.status = 1;
	gettimeofday(&data->philo.start_sleep, NULL);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;
	pid_t	parent;
	sem_t	*sem;

	data = handle_input(ac, av);
	sem = sem_init(data);
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
