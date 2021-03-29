#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NB_THREAD 2

#define INCREMENT_LIMIT 10

pthread_t threads[NB_THREAD];

typedef struct mutex_data {
	int data;
	pthread_mutex_t mutex;
} mutex_data;

void *job(void *arg)
{
	mutex_data *md = (mutex_data *)arg;
	pthread_t tid = pthread_self();
	printf("bebe chat\n");
	while (md->data < INCREMENT_LIMIT)
	{
		pthread_mutex_lock(&(md->mutex));
		(*md).data++;
		pthread_mutex_unlock(&(*md).mutex);
		printf("thread %ld,  data %i\n", tid, md->data);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main()
{
	mutex_data md;
	int i;

	i = 0;
	md.data = 0;
	if (pthread_mutex_init(&md.mutex, NULL))
	{
		printf("\n mutux initfailed\n");
		return (EXIT_FAILURE);
	}
	while (i++ < NB_THREAD)
	{
		int err = pthread_create(&threads[i], NULL, job, &md);
		if (err)
		{
			printf("Echec de la création du thread: [%s]", strerror(err));
			break;
		}
		printf("creation of thread nb: %ld\n", threads[i]);
	}
	i = 0;
	while (i < NB_THREAD)
		pthread_join(threads[i++], NULL);
	pthread_mutex_destroy(&md.mutex);
	return EXIT_SUCCESS;

}
