#include "philo_one.h"

int	continue_job(int i, t_phi *phi)
{
	return (!phi->simu->has_death &&
			 (!phi->simu->has_option ||
			  i < phi->simu->nb_times_eat));
}

void		*job(void *arg)
{
	int				i;
	t_phi			*phi;
	pthread_mutex_t	*fst_fork;
	pthread_mutex_t	*scd_fork;

	i = 0;
	phi = (t_phi *)arg;
	fst_fork = get_fst_fork(phi);
	scd_fork = get_scd_fork(phi);
	while (continue_job(i, phi))
	{
		take_forks(i, phi, fst_fork, scd_fork);
		if (continue_job(i, phi))
			p_eat(phi, fst_fork, scd_fork);
		if (continue_job(i, phi))
			p_sleep(phi);
		if (continue_job(i, phi))
			p_thinking(phi);
		i++;
	}
}
