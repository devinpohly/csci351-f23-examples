#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <pthread.h>

#define BUFSIZE 256

struct thread_args {
	int cfd;
};

void *serve_client(void *varg)
{
	struct thread_args *arg = varg;
	int cfd = arg->cfd;
	free(varg);

	for (;;) {
		char buf[BUFSIZE];

		int bytes = read(cfd, buf, BUFSIZE);
		if (bytes < 0) {
			perror("read");
			close(cfd);
			return NULL;
		}
		if (bytes == 0) {
			// client closed connection
			break;
		}

		buf[0] = 'j';

		int rv = write(cfd, buf, bytes);
		if (rv < 0) {
			perror("write");
			close(cfd);
			return NULL;
		}
		if (rv < bytes) {
			fprintf(stderr, "short write!\n");
		}
	}

	close(cfd);

	return NULL;
}

int main(void)
{
	// File descriptor
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if (lfd < 0) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in addy;
	addy.sin_family = AF_INET;
	addy.sin_port = htons(9999);
	inet_aton("10.22.81.212", &addy.sin_addr);

	int rv = bind(lfd, (struct sockaddr *) &addy, sizeof(addy));
	if (rv) {
		perror("connect");
		close(lfd);
		return 1;
	}

	rv = listen(lfd, 10);
	if (rv) {
		perror("listen");
		close(lfd);
		return 1;
	}

	// open_listenfd

	for (;;) {
		int cfd = accept(lfd, NULL, NULL);
		if (cfd < 0) {
			perror("accept");
			close(lfd);
			return 1;
		}

		pthread_t thread;
		struct thread_args *arg = malloc(sizeof(*arg));
		arg->cfd = cfd;
		int rv = pthread_create(
				&thread,
				NULL,
				serve_client,
				arg);

		if (rv < 0) {
			perror("pthread_create");
		}
	}

	close(lfd);
	return 0;
}
