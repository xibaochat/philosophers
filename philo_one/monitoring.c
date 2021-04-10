# include "philo_one.h"

void	*monitoring(void *arg)
{
	t_phi *phi;

	phi = (t_phi *)arg;
	while (phi)
	{
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			phi->simu->has_death = 1;
			pthread_mutex_lock(&phi->simu->display);
			printf_message(phi, "died");
			//pthread_mutex_unlock(&phi->simu->display);
			break;
		}
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
		}
}
