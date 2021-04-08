#include "philo_one.h"

// someone reach max nb_times eat times
int any_philo_ate_max_meals(t_phi *phi_i)
{
	t_phi *link;

	link = phi_i->head;
	while (link)
	{
		if (link->actual_eat_time >= link->simu->nb_times_eat)
			return (++link->phi_id);
		link = link->next;
	}
	return (0);
}

int	meals_times_reach_max(t_phi *phi_i)
{
	int	id;

	id = 0;
	if (phi_i->simu->nb_times_eat != -1)
	{
		id = any_philo_ate_max_meals(phi_i);
		if (id)
			phi_i->simu->has_death = 1;
	}
	return (id);
}

int	eating_time_gap_more_than_given_time(t_phi *phi_i)
{
	unsigned long	s_t;
	t_phi			*head;
	unsigned long	eat_gap;
	int				future;

	head= phi_i->head;
	s_t = phi_i->simu->start_time;
	eat_gap = get_timestamp(s_t) - phi_i->last_meal;
	while (head)
	{
		if (!head->actual_eat_time && head->phi_id == 0)
			future = 0;
		else
			future = 10; //phi_i->simu->die_time;
		if (eat_gap + 0 >= phi_i->simu->die_time)
		{
			phi_i->simu->has_death = 1;
			return (++head->phi_id);
		}
		head = head->next;
	}
	return (0);
}

int	someone_died(t_phi *phi_i)
{
	int	id;

	id = 0;
	id = eating_time_gap_more_than_given_time(phi_i);
	if (id)
		show_dead_message(id, phi_i->simu->start_time);
	return (id);
}
