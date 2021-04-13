# include "philo_two.h"

int		eat_max_meal(t_simu *simu)
{
	if (simu->has_option != -1
		&& simu->finish_meal == simu->nb_p)
		return (1);
	return (0);
}

int		die_condition(t_phi *phi)
{
	if ((get_actual_time() - phi->last_meal > phi->simu->die_time)
		&& !eat_max_meal(phi->simu))
		return (1);
	return (0);
}

void	*monitoring(void *arg)
{
	t_phi *phi;

	phi = (t_phi *)arg;
	while (phi && ((phi->simu->has_option == -1) || (phi->simu->has_option != -1 && phi->simu->finish_meal < phi->simu->nb_p)))
	{
		if (phi->simu->has_option != -1)
		{
			if (phi->simu->finish_meal >= phi->simu->nb_p)
				break;
		}
		if (die_condition(phi))
		{
			sem_wait(phi->simu->death);
			phi->simu->has_death = 1;
			sem_post(phi->simu->death);
			sem_wait(phi->simu->display);
			printf_message(phi, "died");
			sem_post(phi->simu->display);
			break;
		}
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
		}
	usleep(10);
}
