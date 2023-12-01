#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int counter = 0;

void *thread_main(void *arg)
{
	for (int i = 0; i < 1000; i++) {
		usleep(1000);
		pthread_mutex_lock(&mutex);
		counter++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(void)
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t thr[10];
	for (int i = 0; i < 10; i++) {
		pthread_create(&thr[i],
			NULL,
			thread_main,
			NULL);
	}
	for (int i = 0; i < 10; i++) {
		pthread_join(thr[i], NULL);
	}
	printf("%d\n", counter);
	pthread_mutex_destroy(&mutex);
	return 0;
}
