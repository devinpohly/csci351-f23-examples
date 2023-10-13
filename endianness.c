#include <stdio.h>

int main(void)
{
	int num = 351351;

	int *p = &num;
	// addr = addr
	char *c = (char *) p;

	printf("%02x %02x %02x %02x\n",
		c[0], c[1], c[2], c[3]);

	return 0;
}
