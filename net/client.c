#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(void)
{
	// File descriptor
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in addy;
	addy.sin_family = AF_INET;
	addy.sin_port = htons(9999);
	inet_aton("10.22.81.212", &addy.sin_addr);

	int rv = connect(fd, (struct sockaddr *) &addy, sizeof(addy));
	if (rv) {
		perror("connect");
		close(fd);
		return 1;
	}

	char buf[256];
	strcpy(buf, "hello world\n");
	int len = strlen(buf);

	rv = write(fd, buf, len);
	if (rv < 0) {
		perror("write");
		close(fd);
		return 1;
	}
	if (rv < len) {
		fprintf(stderr, "short write!\n");
	}

	rv = read(fd, buf, sizeof(buf) - 1);
	if (rv < 0) {
		perror("read");
		close(fd);
		return 1;
	}

	buf[rv] = '\0';
	printf("%s", buf);

	close(fd);
	return 0;
}
