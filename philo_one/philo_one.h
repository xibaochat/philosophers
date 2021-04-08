/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 03:48:54 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/21 03:49:08 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

# define WARNING_MESSAGE "Please use this command :\n"
# define ARG1 "./philo_one number_of_philosopher "
# define ARG2 "time_to_die time_to_eat "
# define ARG3 "time_to_sleep "
# define ARG4 "[number_of_time_each_philosophers_must_eat]\n"

typedef struct s_simu
{
	unsigned long	die_time;
	int				time_spend_eat;
	int				time_spend_sleep;
	int				nb_times_eat;
	unsigned long	start_time;
	int				has_death;
}				t_simu;

typedef struct s_phi
{
	int				wait;
	int				phi_id;
	struct s_phi	*head;
	struct s_phi	*next;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	unsigned long	last_meal;
	int				actual_eat_time;
	t_simu			*simu;
}				t_phi;

pthread_mutex_t	*init_fork(int nb);
t_phi			*create_node_list(pthread_mutex_t *f, int n, char **av, t_simu *s);
int				ft_atoi(const char *s);
void			init_phi_fork(int nb, pthread_mutex_t *f, t_phi *current_node);
void			ft_free_var(t_phi *head, pthread_mutex_t *fork);
size_t			ft_strlen(const char *str);
int				valid_input(int ac, char **av);
int				ft_isdigit(int c);
void			show_err_message(char *str);
unsigned long	get_actual_time(void);
void			*job(void *arg);
void			init_simulation_info(t_simu *sti, char **av);
t_simu			*init_simu_thread(char **av);
unsigned long	get_actual_time(void);
unsigned long	get_timestamp(unsigned long start_time);
pthread_mutex_t	*get_current_fork(t_phi *phi_i);
pthread_mutex_t	*get_next_fork(t_phi *phi_i);
void			show_dead_message(int id, unsigned long t);
int				someone_died(t_phi *phi_i);
int				meals_times_reach_max(t_phi *phi_i);
int				any_philo_ate_max_meals(t_phi *phi_i);
int				meals_times_reach_max(t_phi *phi_i);
pthread_mutex_t		*init_mutex_fork(int n);


#endif
