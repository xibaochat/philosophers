#include "philo_two.h"

int	continue_job(int i, t_phi *phi)
{
	usleep(10);
	if (!phi->simu->has_death &&
		(!phi->simu->has_option ||
		 i < phi->simu->nb_times_eat))
	{
		return (1);
	}
	return(0);
}

void		*job(void *arg)
{
	int				i;
	t_phi			*phi;

	i = 0;
	phi = (t_phi *)arg;
	while (continue_job(i, phi))
	{
		take_forks(i, phi);
		if (continue_job(i, phi))
			p_eat(phi);
		if (continue_job(i, phi))
			p_sleep(phi);
		if (continue_job(i, phi))
			p_thinking(phi);
		i++;
	}
	if (phi->simu->has_option &&
		i == phi->simu->nb_times_eat)
		phi->simu->finish_meal++;
		return (NULL);
}
