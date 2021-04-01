#include "philo_one.h"

void *job(void *arg)
{
	t_phi *phi_i;

	phi_i = (t_phi *)arg;
	pthread_mutex_lock(&(phi_i->left_fork->mutex));
	printf("%d is eating\n", phi_i->phi_id);
	sleep(phi_i->wait);
	pthread_mutex_unlock(&(phi_i->left_fork->mutex));
	printf("%d finish eating\n", phi_i->phi_id);
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	int i = 0;
	int nb = 5;
	t_phi *tmp;
	int wait_time = 5;
	t_fork *fork_info;
	t_phi *head;

	fork_info = init_fork(nb);
	head = create_node_list(fork_info, nb);
	tmp = head;
	while(tmp)
	{
		printf("id is %d left:%d right:%d\n", tmp->phi_id, tmp->left_fork->id, tmp->right_fork->id);
		tmp->wait = wait_time--;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		pthread_create(&tmp->thread, NULL, &job, tmp);
		tmp = tmp->next;
	}
	write(0, "ici0\n", 5);
	tmp = head;
	while (tmp)
	{
        pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
	tmp = head;
	write(0, "ici1\n", 5);
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(tmp->fork_info[i].mutex));
		i++;
	}
	write(0, "ici2\n", 5);
	return (0);
}
