#include <stdio.h>
#include <stdlib.h>

int main() {
	//int *ptr;
	int *vet = (int*) malloc(2*sizeof(int));
	printf("Na stack &vet = %p | Valor: %p\n", &vet, vet);
	//printf("Na stack &ptr = %p | Valor: %p\n", &ptr, ptr);
	//ptr = vet;
	printf("ptr = vet\n");
	printf("Na stack &vet = %p | Valor: %p\n", &vet, vet);
	//printf("Na stack &ptr = %p | Valor: %p\n", &ptr, ptr);

	vet[1] = 420;
	printf("vet[1] = %d\n", vet[1]);

	free(vet);
	vet = NULL;
	printf("free(vet)\n");
	printf("Na stack &vet = %p | Valor: %p\n", &vet, vet);
	//printf("Na stack &ptr = %p | Valor: %p\n", &ptr, ptr);

	int *vet1 = (int*) malloc(2*sizeof(int));
	vet1[1] = 69;
	//vet[1] = 420;
	printf("vet[1] = %d\n", vet[1]);

	/*printf("%d\n", *ptr);
	ptr++;
	printf("%d\n", *ptr);
	ptr++;
	printf("%d\n", *ptr);	// not possible to access memory space that was freed
*/
	return 0;
}
