#include <stdio.h>
#include <stdarg.h>

/**
 * Imprime em sequência um inteiro, um real e uma string
*/
void teste(int cont, ...) {
	va_list args;
	va_start(args, cont);

	int arg0 = va_arg(args, int);
	printf("(int)    Arg0: %d\n", arg0);

	double arg1 = va_arg(args, double);
	printf("(double) Arg1: %3lf\n", arg1);

	char* arg2 = va_arg(args, char*);
	printf("(char*)  Arg2: %s\n", arg2);

	va_end(args);
}

int main() {
	teste(3, 4, 3.14, "Olá, mundo!");

	return 0;
}