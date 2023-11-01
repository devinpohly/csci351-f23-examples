#include <stdio.h>

int main(void)
{
	// higher level - C standard
	// fopen, fclose, fread, fwrite
	// printf, fprintf
	// scanf, fscanf
	// fgets
	// (stdio)
	FILE *fp = fopen("test.txt", "r+");
	if (fp == NULL) {
		perror("fopen");
		return 1;
	}

	int arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = i * i;
	}
	fwrite(&arr, sizeof(int), 16, fp);


	fclose(fp);
	
	// lower level - UNIX interface
	// open, close, read, write

	return 0;
}
