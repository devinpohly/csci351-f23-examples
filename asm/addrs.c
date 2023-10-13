#include <stdio.h>
#include <stdlib.h>

int g;

void f(void) {
	return ;
}

int main(void)
{
	static int s;
	int i;
	int *p = malloc(sizeof(int));

	printf("&g: %p\n", &g);
	printf("&f: %p\n", &f);
	printf("&s: %p\n", &s);
	printf("&i: %p\n", &i);
	printf("p: %p\n", p);
	printf("&p: %p\n", &p);
	printf("&printf: %p\n", &printf);

	return 0;
}
