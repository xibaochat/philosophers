# include "philo_one.h"

void	*monitoring(void *arg)
{
	t_phi *phi;

	phi = (t_phi *)arg;
	while (phi && !phi->simu->has_death)
	{
		if (phi->simu->is_died)
			break;
		pthread_mutex_lock(&phi->eat_lock);
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			printf("ici nb %d %ld %ld\n", phi->phi_id + 1, get_actual_time(), phi->last_meal);
			phi->simu->has_death = 1;
			phi->simu->is_died = 1;
			printf_message(phi, "died");
			pthread_mutex_unlock(&phi->eat_lock);
			break;
		}
		pthread_mutex_unlock(&phi->eat_lock);
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
		}
}
