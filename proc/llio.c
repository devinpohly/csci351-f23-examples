#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	// lower level - UNIX interface
	// open, close, read, write

	// file descriptor
	int fd = open("lltest.link.ganon.zelda",
		O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0) { 
		perror("open");
		return 1;
	}

	int arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = i * i;
	}
	write(fd, &arr, sizeof(int) * 16);

	close(fd);
	
	return 0;
}
