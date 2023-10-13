#include <stdio.h>

int main(void)
{
	float total = 0;
	total += 1000000000;

	for (int i = 0; i < 1000000; i++) {
		total += 64.0;
	}


	printf("%f\n", total);

	return 0;
}
