# include "philo_two.h"

void	*monitoring(void *arg)
{
	t_phi *phi;

	phi = (t_phi *)arg;
	while (phi && phi->simu->has_death == 0)
	{
		if (phi->simu->is_died)
			break;
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			sem_wait(phi->eating);
			phi->simu->has_death = 1;
			phi->simu->is_died = 1;
			printf_message(phi, "died");
			sem_post(phi->eating);
			break;
		}
		sem_post(phi->eating);
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
		usleep(1000);
	}
	return (NULL);
}
