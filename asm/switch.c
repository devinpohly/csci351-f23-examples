#include <stdio.h>
#include <stdlib.h>

long foo(long x, long op) {
	int arr[100];
	switch (op) {
		case 1:
			x += 2;
			break;
		case 2:
			x -= 3;
			break;
		case 3:
			x <<= 8;
			break;
		case 4:
			x /= 3;
			break;
		case 5:
			x *= x;
			break;
		default:
			x = 0;
			break;
	}
	arr[99] = x;
	return x;
}

int main(int argc, char **argv)
{
	int op;
	int a, b, c, y;
	sscanf(argv[1], "%d", &op);
	printf("%d\n", foo(10, op));
	printf("%d\n", y);
	return 0;
}
