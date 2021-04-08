#include "philo_one.h"

pthread_mutex_t	*get_current_fork(t_phi *phi_i)
{
	if (phi_i->phi_id % 2)
		return (phi_i->right_fork);
	return (phi_i->left_fork);
}

pthread_mutex_t	*get_next_fork(t_phi *phi_i)
{
	if (phi_i->phi_id % 2)
		return (phi_i->left_fork);
	return (phi_i->right_fork);
}
