#include <stdio.h>

int main() {
	int cont, sum;
	for (cont = 0, sum = 0;
		 cont < 10;
		 sum += ++cont);

	printf("cont = %d | sum = %d\n", cont, sum); // cont = 10, sum = 55

	return 0;
}
