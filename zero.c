#include <stdio.h>

int main(void)
{
	float x = 1.0;
	float y = -0.0;
	float infinity_really = 1.0 / 0.0;
	float nan = 0.0 / 0.0;

	printf("%e\n", nan);
	printf("%d\n", nan == nan);
	return 0;
}
