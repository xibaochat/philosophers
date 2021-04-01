#include "philo_one.h"

void	odd_nb_lock(t_phi *phi_i)
{
	int	rv0;
	int	rv1;

	rv0 = pthread_mutex_lock(&(phi_i->left_fork->mutex));
	if (!rv0)
	{
		rv1 = pthread_mutex_lock(&(phi_i->right_fork->mutex));
		if (!rv1)
		{
			printf("success %d is eating\n", phi_i->phi_id);
			sleep(1);
			pthread_mutex_unlock(&(phi_i->right_fork->mutex));
			pthread_mutex_unlock(&(phi_i->left_fork->mutex));
			printf("the guy:%d, finish\n", phi_i->phi_id);
		}
		else
			pthread_mutex_unlock(&(phi_i->left_fork->mutex));
	}
	else
		pthread_mutex_unlock(&(phi_i->left_fork->mutex));
}

void	even_nb_lock(t_phi *phi_i)
{
	int	rv0;
	int	rv1;

	rv0 = pthread_mutex_lock(&(phi_i->right_fork->mutex));
	if (!rv0)
	{
		rv1 = pthread_mutex_lock(&(phi_i->left_fork->mutex));
		if (!rv1)
		{
			printf("success %d is eating\n", phi_i->phi_id);
			sleep(1);
			pthread_mutex_unlock(&(phi_i->left_fork->mutex));
			pthread_mutex_unlock(&(phi_i->right_fork->mutex));
			printf("the guy:%d, finish\n", phi_i->phi_id);
		}
		else
			pthread_mutex_unlock(&(phi_i->right_fork->mutex));
	}
	else
		pthread_mutex_unlock(&(phi_i->right_fork->mutex));
}
