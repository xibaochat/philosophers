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

//	write(1, "ICI\n", 5);
	t = p->simu->start_time;
	sem_wait(p->simu->display);
	printf("%ld %d %s\n", get_timestamp(t), p->phi_id + 1, s);
	/* printf("***%ld***\n", get_timestamp(t)); */
	/* write(1, "ICI0\n", 6); */
	/* printf("***%d***\n", p->phi_id + 1); */
	/* write(1, "ICI1\n", 6); */
	/* printf("***%s***\n", s); */
	/* write(1, "ICI000\n", 8); */
	sem_post(p->simu->display);
//	printf("enf of printf\n");
}
