#include <stdio.h>
#include <stdint.h>

int main(void)
{
	unsigned int class = 0x15f;
	unsigned int weird = 1000000000;
	unsigned long weird2;

	printf("Dec %u\nOct %o\nHex %x\n",
			class, class, class);

	printf("%u\n", weird);

	weird2 = weird;
	weird2 *= 5;
	printf("%lu\n", weird2);

	return 0;
}
