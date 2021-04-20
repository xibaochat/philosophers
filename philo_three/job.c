#include "philo_three.h"

void		*job(void *arg)
{
	t_phi			*phi;

	phi = (t_phi *)arg;
	while (1 && !phi->simu->has_death)
	{
		eat(phi);
		if (phi->simu->has_option
		&& phi->actual_eat_time >= phi->simu->nb_times_eat)
		{
			phi->simu->is_died = 1;
			break;
		}
		if (phi->simu->has_death)
			break;
		p_sleep(phi);
		if (phi->simu->has_death)
            break;
		p_thinking(phi);
		usleep(10);
	}
	exit(1);
}
