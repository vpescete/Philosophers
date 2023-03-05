/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:23:35 by vpescete          #+#    #+#             */
/*   Updated: 2023/03/05 18:04:47 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SLEEP "is sleeping"
# define FORK "has taken a fork"
# define EAT "is eating"
# define THINK "is thinking"
# define DEAD "died"

/* DEFINE STRUCT */
struct s_data;

typedef struct s_philo {
	
	struct s_data	*data;
	pthread_t       t1;
	int             id;
	int             eat_count;
	int             status;
	int				prev_status;
	unsigned long	ttd;
	struct timeval	start_sleep;
	struct timeval	start_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	
}				t_philo;

typedef struct s_data {
	
	pthread_t       	*tid;
	int             	philo_num;
	int             	meals_nb;
	int             	dead;
	int             	finished;
	t_philo				*philos;
	unsigned long       death_time;
	unsigned long       eat_time;
	unsigned long       sleep_time;
	struct timeval		start_time;
	pthread_mutex_t		*forks;
	
}				t_data;

/* MINILIBFT FUNCTION */
int				ft_atoi(char *s);

/* HANDLE INPUT */
t_data			*handle_input(int ac, char **av);
void			handle_input_error(void);

/* ALLOCATE FUNCTION */ 
t_data			*allocate_data(char **av, char ac);
void			allocate_philos(t_philo	*philos, t_data *data);
void			*start_execute(void *data);
unsigned long	ft_gettimestamp(struct timeval goddog);

/* ROUTINE STATUS */ 
int				checker(t_philo *philo, int i);
void			status_zero(t_philo *philo);
void			status_one(t_philo *philo);
void			status_two(t_philo *philo);
void			status_three(t_philo *philo);
void			routine(t_philo *data);

#endif