#include <stdio.h>

int arr[100];

int main(void)
{
	printf("%p\n", arr);
	printf("%p\n", arr + 5);
	printf("%p\n", &arr[10]);

	return 0;
}
