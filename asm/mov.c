#include <stdio.h>

long test1(long x) {
	return x + 1;
}

void swap(long *a, long *b) {
	long t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	long val = test1(10);
	long second = -1;

	swap(&val, &second);

	printf("%ld\n", val);
	printf("%ld\n", second);
	return 0;
}
