#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct thread_args {
	int a;
	int b;
};

void *thread_main(void *arg)
{
	struct thread_args *args = arg;
	int a = args->a;
	int b = args->b;
	free(arg);

	printf("addition: %d + %d = %d\n", a, b, a+b);
	return NULL;
}

int main(void)
{
	pthread_t thread[10];
	for (int i = 0; i < 10; i++) {
		struct thread_args *args =
			malloc(sizeof(*args));
		args->a = i;
		args->b = i + 2;
		pthread_create(&thread[i], NULL,
				thread_main, args);
	}
	for (int i = 0; i < 10; i++) {
		void *retval;
		pthread_join(thread[i], &retval);
	}
	return 0;
}
