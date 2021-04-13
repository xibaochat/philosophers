#include "philo_two.h"

void	init_fork(t_simu *simu)
{
	simu->fork = sem_open ("fork", O_CREAT | O_EXCL, S_IRWXU, simu->nb_p);
	simu->display = sem_open ("display", O_CREAT | O_EXCL, S_IRWXU, 1);
	simu->death = sem_open ("death", O_CREAT | O_EXCL, S_IRWXU, 1);
	sem_unlink("fork");
	sem_unlink("display");
	sem_unlink("death");
}
