#include "philo_one.h"

void *job(void *arg)
{
	t_phi *phi_i;
	int rv0;
	int rv1;

	phi_i = (t_phi *)arg;
	if (phi_i->phi_id % 2)
	{
		rv0 = pthread_mutex_lock(&(phi_i->left_fork->mutex));
		if (!rv0)
		{
			rv1 = pthread_mutex_lock(&(phi_i->right_fork->mutex));
			if (!rv1)
			{
				printf("success %d is eating\n", phi_i->phi_id);
				sleep(1);
				pthread_mutex_unlock(&(phi_i->right_fork->mutex));
				pthread_mutex_unlock(&(phi_i->left_fork->mutex));
				printf("the guy:%d, finish\n", phi_i->phi_id);
			}
			else
				pthread_mutex_unlock(&(phi_i->left_fork->mutex));
		}
		else
			pthread_mutex_unlock(&(phi_i->left_fork->mutex));
	}
	else
	{
		rv0 = pthread_mutex_lock(&(phi_i->right_fork->mutex));
		if (!rv0)
		{
			rv1 = pthread_mutex_lock(&(phi_i->left_fork->mutex));
			if (!rv1)
			{
				printf("success %d is eating\n", phi_i->phi_id);
				sleep(1);
				pthread_mutex_unlock(&(phi_i->left_fork->mutex));
				pthread_mutex_unlock(&(phi_i->right_fork->mutex));
				printf("the guy:%d, finish\n", phi_i->phi_id);
			}
			else
				pthread_mutex_unlock(&(phi_i->right_fork->mutex));
		}
		else
			pthread_mutex_unlock(&(phi_i->right_fork->mutex));
	}
	return NULL;
}

int main(int ac, char **av)
{
	(void) ac;
	int nb;
	t_phi *tmp;
	int wait_time = 5;
	t_fork *fork_info;
	t_phi *head;
	int i;

	nb = ft_atoi(av[1]);
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
		pthread_mutex_destroy(&(fork_info[i].mutex));
		i++;
	}
	write(0, "ici2\n", 5);
	ft_free_var(head, fork_info);
	return (0);
}
