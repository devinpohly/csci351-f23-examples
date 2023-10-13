#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig_num) {
	printf("nice try\n");
}

int main(void)
{
	int pid = getpid();
	printf("pid = %d\n", pid);
	signal(SIGINT, handle_sigint);
	//signal(SIGQUIT, handle_sigint);
	signal(SIGTERM, handle_sigint);
	signal(SIGTSTP, handle_sigint);
	signal(SIGKILL, handle_sigint);
	while (1) {
		kill(pid, SIGINT);
		sleep(1);
	}
	return 0;
}
