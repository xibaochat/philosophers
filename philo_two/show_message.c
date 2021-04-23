#include "philo_two.h"

int	err_create_thread(t_phi *p, char *s)
{
	printf("%s", s);
	ft_free_var(p);
	return (1);
}

int	err_terminate_thread(t_phi *p)
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
	sem_wait(p->simu->display);
	t = p->simu->start_time;
	printf("%ld %d %s\n", get_timestamp(t), p->phi_id + 1, s);
	if (p->simu->has_death && p->simu->is_died)
        p->simu->is_died = 0;
	sem_post(p->simu->display);
}
