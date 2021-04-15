#include "philo_two.h"

void		*job(void *arg)
{
	int				i;
	t_phi			*phi;

	i = 0;
	phi = (t_phi *)arg;
	while (!phi->simu->has_death)
	{
		eat(phi);
//		write(1, "BOID2\n", 6);
		if (phi->simu->has_death || (phi->simu->has_option
		&& phi->actual_eat_time > phi->simu->nb_times_eat))
		{
			phi->simu->is_died = 1;
			break;
		}
//		write(1, "BOID3\n", 6);
		if (!phi->simu->has_death)
			p_sleep(phi);
//		write(1, "BOID4\n", 6);
		if (!phi->simu->has_death)
			p_thinking(phi);
//		write(1, "BOID5\n", 6);
	}
	return (NULL);
}
