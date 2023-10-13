#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
	printf("pid before %d\n", getpid());
	printf("ppid before %d\n", getppid());

	int status;
	int childpid = fork();
	if (childpid > 0) {
		// this is the parent, fall through
	} else if (childpid == 0) {
		printf("child after fork %d\n", getpid());
		execlp("ls", "ls", "-l", NULL);
		// error
		perror("execlp");
		return 1;
	} else {
		// error
		perror("fork");
		return 1;
	}

	while (1) {
		sleep(1);
	}

	int ret = waitpid(childpid, &status, 0);
	if (ret == -1) {
		perror("waitpid");
		return 1;
	}
	
	// parent
	if (WIFEXITED(status)) {
		printf("status %d\n", WEXITSTATUS(status));
	} else if (WIFSTOPPED(status)) {
		printf("stopped with signal %d\n", WSTOPSIG(status));
	} else if (WIFCONTINUED(status)) {
		printf("continue\n");
	} else {
		// assert(WIFSIGNALED(status));
		printf("terminated by signal %d\n", WTERMSIG(status));
	}
	printf("parent after %d\n", getpid());

	return 0;
}
