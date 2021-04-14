# include "philo_two.h"

void	*monitoring(void *arg)
{
	t_phi *phi;
	int		i;

	phi = (t_phi *)arg;
	i = 0;
	while (phi)
	{
		if (phi->simu->has_option)
		{
			if (phi->actual_eat_time >= phi->simu->nb_times_eat)
				i++;
			if (i >= phi->simu->nb_p)
			{
				phi->simu->has_death = 1;
				break;
			}
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
