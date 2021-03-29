#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func_0(void *arg)
{
	int *i = (int *)arg;
	(*i)++;
	printf("ici in the thread\n");
//	printf("arg ici is %d\n", ++*(int*)(arg));
	pthread_exit(EXIT_SUCCESS);
}

int main()
{
	pthread_t thread1;
	int i;

	i = 888;
	printf("before i is %d\n", i);
	pthread_create(&thread1, NULL, func_0, &i);
	pthread_join(thread1, NULL);
	printf("after i is %d\n", i);
	return EXIT_SUCCESS;
}
