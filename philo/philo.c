/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:03:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/22 10:12:58 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_data *data)
{
	(void)data;
	return (0);
}

int main(int ac, char **av)
{
	// pthread_t	tid;
	// pthread_create(&tid, NULL, &routine, &data);

	// pthread_mutex_t	mutex;
	// phtread_mutex_init(&mutex, NULL);
	if (handle_input(ac, av) == 0)
		return (0);
	return (0);
}
