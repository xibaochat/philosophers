#include "philo_one.h"

void *job(void *arg)
{
	t_phi *phi_i;

	phi_i = (t_phi *)arg;
	pthread_mutex_lock(&(phi_i->left_fork->mutex));
	printf("i am eating\n");
	pthread_mutex_unlock(&(phi_i->left_fork->mutex));
	printf("i finish eating\n");
}

t_phi* create_node_list()
{
	int nb;
	int i;
	t_phi *prev;
	t_phi *head;
	t_phi *current_node;
	t_fork *fork_info;

	nb = 5;
	i = 0;
	current_node = NULL;
	fork_info = init_fork(nb);
	while (i < nb)
	{
		current_node = (t_phi *)malloc(sizeof(t_phi));
		current_node->phi_id = i;
		init_phi_fork(nb, &fork_info, i, &current_node);
		current_node->next = NULL;
		if (i == 0)
		{
			head = current_node;
			prev = head;
		}
		else
		{
			prev->next = current_node;
			prev = current_node;
		}
		i++;
	}
	return (head);
}

int main()
{
	int i = 0;
	int nb = 5;
	t_phi *head = create_node_list(fork);
	t_phi *tmp;
	tmp = head;
	while(tmp)
	{
		printf("id is %d left:%d right:%d\n", tmp->phi_id, tmp->left_fork->id, tmp->right_fork->id);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		pthread_create(&tmp->thread, NULL, job, tmp);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
        pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		pthread_mutex_destroy(&(*(tmp->fork_info))->mutex);
		tmp = tmp->next;
	}
	return (0);
}
