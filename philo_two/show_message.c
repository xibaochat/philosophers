#include "philo_two.h"

int		err_create_thread(t_phi *p, char *s)
{
	printf("%s", s);
	ft_free_var(p);
	return (1);
}

int		err_terminate_thread(t_phi *p)
{
	printf("pthread join for philosopher is failed\n");
	ft_free_var(p);
	return (1);
}

void	printf_message(t_phi *p, char *s)
{
	unsigned long	t;

	t = p->simu->start_time;
	sem_wait(p->simu->display);
	printf("%ld %d %s\n", get_timestamp(t), p->phi_id + 1, s);
	sem_post(p->simu->display);
}
