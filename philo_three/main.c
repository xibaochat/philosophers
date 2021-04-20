#include "philo_three.h"

int	monitoring_threads(t_phi *phi)
{
	int	i;

	i = -1;
	while (phi && ++i < phi->simu->nb_p)
	{
		if (pthread_join(phi->monitor, NULL))
			return (1);
		phi = phi->next;
	}
	return (0);
}

void	pilo_process(t_phi *phi)
{
	int		i;
	t_phi	*tmp;

	i = -1;
	tmp = phi;
	phi->simu->start_time = get_actual_time();
	while (phi && ++i < phi->simu->nb_p)
	{
		printf("Here\n");
		if (!i % 2)
			init_process(phi, i);
		usleep(70);
		phi = phi->next;
	}
	i = -1;
	phi = tmp;
	while (phi && ++i < phi->simu->nb_p)
	{
		printf("again\n");
		if (!i % 2)
			init_process(phi, i);
		usleep(70);
		phi = phi->next;
	}
}

void	kill_philo(t_phi *phi)
{

	int	i;

	i = -1;
	while (++i < phi->simu->nb_p)
		kill(phi->simu->pid[i], SIGKILL);
}

void track_child(t_phi *phi)
{
	/* int i; */
	/* int	status; */
	/* int	exit_val; */

	/* i = -1; */
	/* waitpid(-1, &status, 0); */
	/* if (WIFEXITED(status)) */
	/* { */
	/* 	exit_val = WEXITSTATUS(status); */
	/* 	if (exit_val == 42 || exit_val == 2) */
	/* 	{ */
	/* 		kill_philo(phi); */
	/* 		return; */
	/* 	} */
	/* } */
	int             status;
    int             status_value;
    unsigned long   i;

    i = 0;
    while (i < phi->simu->nb_p)
    {
        waitpid(-1, &status, 0);
        if ((WIFEXITED(status) || WIFSIGNALED(status)))
        {
            if ((status_value = WEXITSTATUS(status)) == 0)
            {
                while (i < phi->simu->nb_p)
                {
                    if (i != phi->simu->nb_p)
                        kill(phi->simu->pid[i], SIGTERM);
                    i++;
                }
                break ;
            }
            else if (status_value == 1)
                i++;
        }
    }
}

int	main(int ac, char **av)
{
	int		err_input;
	t_phi	*phi;
	t_simu	*simu;
	pthread_t monitor;

	err_input = valid_input(ac, av);
	if (err_input)
		return (1);
	simu = init_simu(av);
	if (!simu)
		return (1);
	phi = init_phi_node(av, simu);
	if (!phi)
		return (1);
	pilo_process(phi);
	track_child(phi);
	monitoring_threads(phi);
	ft_free_var(phi);
	return (0);
}
