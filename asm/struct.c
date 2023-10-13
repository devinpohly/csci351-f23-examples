#include <stdio.h>

struct foo {
	char d;
	char e;
	/* char f; */
	/* long y; */
	/* int x; */
	/* int z; */
	char c;
};

int main(void)
{
	struct foo f;
	printf("%d\n", sizeof(f));
	printf("offset c: %d\n", (char *) (&f.c) - (char *) &f);
	/* printf("offset x: %d\n", (char *) (&f.x) - (char *) &f); */
	/* printf("offset d: %d\n", (char *) (&f.d) - (char *) &f); */
	/* printf("offset y: %d\n", (char *) (&f.y) - (char *) &f); */
	/* printf("offset e: %d\n", (char *) (&f.e) - (char *) &f); */
	/* printf("offset z: %d\n", (char *) (&f.z) - (char *) &f); */
	/* printf("offset f: %d\n", (char *) (&f.f) - (char *) &f); */
	return 0;
}
