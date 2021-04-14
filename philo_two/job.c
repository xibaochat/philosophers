#include "philo_two.h"

int	continue_job(int i, t_phi *phi)
{
//	usleep(10);
	if (!phi->simu->has_death &&
		(!phi->simu->has_option||
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
	while (!phi->simu->has_death)
	{
		take_forks(i, phi);
		p_eat(phi);
		if (phi->simu->has_death || (phi->simu->has_option
		&& phi->actual_eat_time >= phi->simu->nb_times_eat))
		{
			phi->simu->is_died = 1;
			break;
		}
		if (!phi->simu->has_death)
			p_sleep(phi);
		if (!phi->simu->has_death)
			p_thinking(phi);
	}
	return (NULL);
}
