#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr;
	int *vet = malloc(1024);
	ptr = vet;
	
	printf("vet = %p\n", vet);
	printf("ptr = %p\n", ptr);

	free(vet);
	ptr[2] = 3;

	printf("%d\n", *ptr);
	ptr++;
	printf("%d\n", *ptr);
	ptr++;
	printf("%d\n", *ptr);	// not possible to access memory space that was freed

	return 0;
}
