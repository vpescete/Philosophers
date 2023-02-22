/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:18:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/22 12:18:57 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	allocate_data(t_data *data, char **av, char ac)
{
	if (!data)
		return ; // must to handle this error 
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = ft_atoi(av[5]);
	printf("philo_num: %d\n", data->philo_num);
	printf("death_time: %llu\n", data->death_time);
	printf("eat_time: %llu\n", data->eat_time);
	printf("sleep_time: %llu\n", data->sleep_time);
	if (ac == 6)
		printf("meals_nb: %d\n", data->meals_nb);
}

void	allocate_philos(t_philo	*philos, t_data *data)
{
	if (!philos)
		return ;
	philos->data = data;
	philos->eat_cont = data->meals_nb;

}