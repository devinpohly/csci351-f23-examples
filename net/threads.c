#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_main(void *arg)
{
	int *iarg = arg;
	int i = *iarg;
	free(arg);

	printf("hi from thread %d\n", i);
	return NULL;
}

int main(void)
{
	pthread_t thread[10];
	for (int i = 0; i < 10; i++) {
		int *myi = malloc(sizeof(int));
		*myi = i;
		pthread_create(&thread[i], NULL, thread_main, myi);
	}
	for (int i = 0; i < 10; i++) {
		pthread_join(thread[i], NULL);
	}
	return 0;
}
