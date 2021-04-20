#include "philo_three.h"

int		err_terminate_thread(t_phi *p)
{
	printf("pthread join for philosopher is failed\n");
	ft_free_var(p);
	return (1);
}

void	printf_message(t_phi *p, char *s)
{
	unsigned long	t;

	if (p->simu->has_death && !p->simu->is_died)
		return ;
	else if (p->simu->is_died)
		p->simu->is_died = 0;
	sem_wait(p->simu->display);
	t = p->simu->start_time;
	printf("%ld %d %s\n", get_timestamp(t), p->phi_id + 1, s);
	sem_post(p->simu->display);
}
