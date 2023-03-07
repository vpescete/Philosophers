/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:36 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/07 18:45:17 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <semaphore.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

# define SLEEP "is sleeping"
# define FORK "has taken a fork"
# define EAT "is eating"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_philo {
	int					id;
	int					status;
	int					eat_count;
	struct timeval		start_sleep;
	struct timeval		start_eat;
}				t_philo;

typedef struct s_data {
	int					philo_num;
	int					meals_nb;
	unsigned long		death_time;
	unsigned long		eat_time;
	unsigned long		sleep_time;
	struct timeval		start_time;
	t_philo				philo;
	sem_t				*sem;
	sem_t				*print;
	pid_t				parent;
}				t_data;

/* UTILS FUNCTION */
unsigned long	ft_gettimestamp(struct timeval goddog);
int				ft_atoi(char *s);
void			check_if_is_dead(t_data *data);

/* INPUT FUNCTION */
t_data			*handle_input(int ac, char **av);
int				check_input_int(int ac, char **av);
void			handle_input_error(void);

/* INIT FUNCITON */
t_data			*allocate_data(char **av, char ac);
void			sem_initialize(t_data *data);

/* STATUS FUNCTION */
void			execute_child(t_data *data);
void			status_zero(t_data *data);
void			status_one(t_data *data);
void			status_two(t_data *data);
void			status_three(t_data *data);
void			run_parent_process(t_data *data);

#endif