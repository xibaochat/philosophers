#include "philo_three.h"

void	init_process(t_phi *phi, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (!pid)
	{
		printf("create thread %d\n", pid);
		pthread_create(&phi->monitor, NULL, monitoring, phi);
		printf("access job %d\n", pid);
		job(phi);
		printf("done with job %d\n", pid);
		pthread_join(phi->monitor, NULL);
	}
	else
		phi->simu->pid[i] = pid;
}
