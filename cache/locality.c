#include <stdio.h>
#include <stdlib.h>

#define DIM 40000

int main(void)
{
	long (*arr)[DIM] = malloc(sizeof(long) * DIM * DIM);

	long sum = 0;
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			// try and poke it?
			arr[i][j] = 1;
			sum += arr[i][j];
		}
	}
	printf("%ld\n", sum);

	// ok i should free too
	return 0;
}
