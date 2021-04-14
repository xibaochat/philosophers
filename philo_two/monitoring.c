# include "philo_two.h"

void	*monitoring(void *arg)
{
	t_phi *phi;

	phi = (t_phi *)arg;
	while (phi && ((!phi->simu->has_option) || (phi->simu->finish_meal < phi->simu->nb_p)))
	{
		if (phi->simu->has_option)
		{
			if (phi->simu->finish_meal >= phi->simu->nb_p)
				break;
		}
		sem_wait(phi->eating);
		if (get_actual_time() - phi->last_meal > phi->simu->die_time)
		{
			if (!phi->simu->has_death)
			{
				phi->simu->has_death = 1;
				printf_message(phi, "died");
				sem_post(phi->eating);
				break;
			}
		}
		sem_post(phi->eating);
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
		usleep(10);
	}
	return (NULL);
}
