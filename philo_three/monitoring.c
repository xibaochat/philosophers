#include "philo_three.h"

void	*monitoring(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	while (1 && phi)
	{
		if (phi->simu->is_died)
			break ;
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			sem_wait(phi->eating);
			phi->simu->has_death = 1;
			phi->simu->is_died = 1;
			sem_wait(phi->simu->display);
			printf("%ld %d is died\n", \
				   get_timestamp(phi->simu->start_time), phi->phi_id + 1);
			sem_post(phi->eating);
			exit(0);
		}
		usleep(10);
	}
	return (NULL);
}
