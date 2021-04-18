#include "philo_one.h"

/* int	continue_job(int i, t_phi *phi) */
/* { */
/* 	usleep(10); */
/* 	if (!phi->simu->has_death && */
/* 		(!phi->simu->has_option || */
/* 		 i < phi->simu->nb_times_eat)) */
/* 	{ */
/* 		return (1); */
/* 	} */
/* 	return(0); */
/* } */

void		*job(void *arg)
{
	t_phi			*phi;
	pthread_mutex_t	*fst_fork;
	pthread_mutex_t	*scd_fork;

	phi = (t_phi *)arg;
	fst_fork = get_fst_fork(phi);
	scd_fork = get_scd_fork(phi);
	while (!phi->simu->has_death)
	{
		p_eat(phi, fst_fork, scd_fork);
		if (phi->simu->has_death || (phi->simu->has_option
			&& phi->actual_eat_time > phi->simu->nb_times_eat))
        {
            phi->simu->is_died = 1;
            break;
        }
		if (!phi->simu->has_death)
			p_sleep(phi);
		else
			break;
		if (!phi->simu->has_death)
			p_thinking(phi);
		else
			break;
	}
	return (NULL);
}
