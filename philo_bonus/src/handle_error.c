/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:04:19 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/06 16:04:44 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	handle_input_error(void)
{
	printf("\n\033[0;31mWRONG INPUT\033[0m\n\n");
	printf("\tRIGHT INPUT:\t\033[0;32m./philo\t[number_of_philosophers]");
	printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
	printf(" (optional)[number_of_times_each_philosopher_must_eat]\033[0m\n\n");
	printf("\t\e[4mAll the arguments has to be integers. the 2nd, ");
	printf("3th and 4th are considered in milliseconds\e[24m\n\n");
}
