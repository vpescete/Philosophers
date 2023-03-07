/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:34:53 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 11:28:19 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_data	*allocate_data(char **av, char ac)
{
	t_data	*data;
	t_philo	philo;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = ft_atoi(av[5]);
	else
		data->meals_nb = 0;
	gettimeofday(&data->start_time, NULL);
	data->philo = philo;
	return (data);
}

void	sem_init(t_data *data)
{
	char	*name;
	char	*toprint;
	sem_t	*sem;
	sem_t	*print;
	
	name = "/forks";
	toprint = "/print";
	sem_unlink(name);
	sem_unlink("/print");
	data->sem = sem_open(name, O_CREAT, 0666, data->philo_num);
	data->print = sem_open(toprint, O_CREAT, 0666, 1);
}