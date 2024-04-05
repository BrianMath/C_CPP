#include <stdio.h>
#define N 100


void toUpper(char* txt) {
	char* p = txt;

	while (*txt) {
		*txt -= 32 * (*txt >= 'a' && *txt <= 'z');
		txt++;
	}
	
	printf("%s\n", p);
}


int main() {
	char nome[N] = "Brian Matheus!";

	toUpper(nome);

	return 0;
}
