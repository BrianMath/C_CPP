#include <stdio.h>
#include <string.h>
#define N 100


void toUpper(char* txt) {
	int tam = strlen(txt);

	for (int i = 0; i < tam; i++) {
		txt[i] -= 32 * (txt[i] >= 'a' && txt[i] <= 'z');
	}
	
	printf("%s\n", txt);
}


int main() {
	char nome[N] = "Brian Matheus!";

	toUpper(nome);

	return 0;
}
