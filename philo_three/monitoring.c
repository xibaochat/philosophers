# include "philo_three.h"

void	*monitoring(void *arg)
{
	t_phi *phi;

	phi = (t_phi *)arg;
	while (1 && phi)
	{
		if (phi->simu->is_died)
			break;
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			phi->simu->has_death = 1;
			sem_wait(phi->eating);
			printf_message(phi, "died");
			sem_post(phi->eating);
			exit(0);
		}
	}
	return (NULL);
}
