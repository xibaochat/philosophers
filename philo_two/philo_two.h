/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 03:48:54 by xinwang           #+#    #+#             */
/*   Updated: 2019/11/21 03:49:08 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

# define WARNING_MESSAGE "Please use this command :\n"
# define ARG1 "./philo_two number_of_philosopher "
# define ARG2 "time_to_die time_to_eat "
# define ARG3 "time_to_sleep "
# define ARG4 "[number_of_time_each_philosophers_must_eat]\n"
# define TAKE_FORK "has taken a fork"
# define P_THREAD_ERR "pthread create for philosopher is failed\n"
# define MONITOR_THREAD_ERR "pthread create for monitoring is failed\n"
# define MES_MUST_EAT "Number_of_times_each_philosopher_must_eat "
# define RED            "\033[1;31m"
# define GR          "\033[1;32m"
# define YELLOW         "\033[1;33m"
# define B           "\033[1;34m"
# define P         "\033[1;35m"
# define CYAN           "\033[1;36m"
# define GREY           "\033[1;37m"
# define WHITE "\033[;0m"
# define BLINK "\e[5m"
# define B_YE  "\e[38;5;11m"
# define ORANGE "\e[38;5;209m"
# define BOLD_GR "\e[1;92m"
# define PINK "\e[38;5;198m"
# define BLUE "\e[38;5;21m"
# define PURPLE "\e[38;5;57m"
# define NC "\033[0;0m"

typedef struct		s_simu
{
	int				nb_p;
	unsigned long	die_time;
	int				time_spend_eat;
	int				time_spend_sleep;
	int				nb_times_eat;
	unsigned long	start_time;
	int				has_death;
	int				is_died;
	int				has_option;
	sem_t			*fork;
	sem_t			*display;
	int				finish_meal;
}					t_simu;

typedef struct		s_phi
{
	int				phi_id;
	struct s_phi	*head;
	struct s_phi	*next;
	unsigned long	last_meal;
	int				actual_eat_time;
	t_simu			*simu;
	sem_t			*eating;
	char			*name;
	pthread_t		thread;

}					t_phi;

int					ft_atoi(const char *s);
void				ft_free_var(t_phi *head);
size_t				ft_strlen(const char *str);
int					valid_input(int ac, char **av);
int					ft_isdigit(int c);
void				show_err_message(char *str);
unsigned long		get_actual_time(void);
void				*routine(void *arg);
void				init_simulation_info(t_simu *sti, char **av);
t_simu				*init_simu_thread(char **av);
unsigned long		get_actual_time(void);
unsigned long		get_timestamp(unsigned long start_time);
void				show_dead_message(int id, unsigned long t);
int					someone_died(t_phi *phi_i);
int					meals_times_reach_max(t_phi *phi_i);
int					any_philo_ate_max_meals(t_phi *phi_i);
int					meals_times_reach_max(t_phi *phi_i);
void				printf_message(t_phi *p, char *s);
int					eating_time_gap_more_than_given_time(t_phi *phi_i);
void				init_simulation_info(t_simu *sti, char **av);
t_simu				*init_simu(char **av);
t_phi				*init_phi_node(t_simu *simu);
int					ft_atoi(const char *s);
size_t				ft_strlen(const char *str);
void				show_dead_message(int id, unsigned long s_t);
int					ft_isdigit(int c);
unsigned long		get_timestamp(unsigned long start_time);
unsigned long		get_time_diff(unsigned long a, unsigned long b);
unsigned long		get_actual_time(void);
void				printf_message(t_phi *p, char *s);
int					err_create_thread(t_phi *p, char *s);
void				*job(void *arg);
int					err_terminate_thread(t_phi *p);
void				p_sleep(t_phi *p);
void				p_thinking(t_phi *p);
void				*monitoring(void *arg);
int					continue_job(int i, t_phi *phi);
void				ft_free_var(t_phi *head);
void				wait_for(long unsigned time);
void				close_sem(t_phi *head);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
void				eat(t_phi *p);
void				show_welcome_message(void);

#endif
