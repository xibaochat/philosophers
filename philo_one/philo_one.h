# ifndef PHOLO_ONE_H
# define PHOLO_ONE_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_fork
{
    int id;
    int in_use;
    pthread_mutex_t mutex;
}           t_fork;

typedef struct      s_phi
{
    int phi_id;
    t_fork* left_fork;
    t_fork* right_fork;
    t_fork* fork;
	t_fork** fork_info;
	struct s_phi   *head;
    struct s_phi   *next;
	pthread_t thread;
}                   t_phi;

t_fork* init_fork(int nb);

void init_phi_fork(int nb, t_fork **fork_info, int i, t_phi **current_node);
t_phi* create_node_list();





#endif
