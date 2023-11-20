#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

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

	int cfd = accept(lfd, NULL, NULL);
	if (cfd < 0) {
		perror("accept");
		close(lfd);
		return 1;
	}

	for (;;) {
		char buf[256];

		int bytes = read(cfd, buf, sizeof(buf));
		if (bytes < 0) {
			perror("read");
			close(cfd);
			close(lfd);
			return 1;
		}
		if (bytes == 0) {
			// client closed connection
			break;
		}

		buf[0] = 'j';

		rv = write(cfd, buf, bytes);
		if (rv < 0) {
			perror("write");
			close(cfd);
			close(lfd);
			return 1;
		}
		if (rv < bytes) {
			fprintf(stderr, "short write!\n");
		}
	}

	close(cfd);
	close(lfd);
	return 0;
}
