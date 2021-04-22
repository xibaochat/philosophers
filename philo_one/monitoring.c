#include "philo_one.h"

void	*monitoring(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	while (phi && !phi->simu->has_death)
	{
		if (phi->simu->is_died)
			break ;
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			pthread_mutex_lock(&phi->eat_lock);
			phi->simu->has_death = 1;
			phi->simu->is_died = 1;
			printf_message(phi, "died");
			pthread_mutex_unlock(&phi->eat_lock);
			break ;
		}
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
	}
}
