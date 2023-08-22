#include <stdio.h>
#include <stdarg.h>

/**
 * @brief Soma uma quantidade indefinida de inteiros
 * 
 * @param cont Quantidade de argumentos que serão recebidos
 * @param ... Lista indefinida de inteiros
 * @return int - A soma dos números recebidos
 */
int sum(int cont, ...) {
	// Lista de argumentos passados
	va_list args;
	// Inicializa a lista de argumentos após o argumento 'cont'
	va_start(args, cont);

	int soma = 0;
	for (int i = 0; i < cont; i++) {
		// Retorna um dos argumentos do tipo especificado ...
		// ... e aponta para o próximo argumento
		int num = va_arg(args, int);
		soma += num;
	}

	// Finaliza a lista de argumentos
	va_end(args);

	return soma;
}

int main() {
	printf("1 + 2 = %d\n", sum(2, 1, 2));
	printf("10 - 1 = %d\n", sum(2, 10, -1));

	int a = 1, b = 2, c = -3, d = 4, e = -5;
	printf("(%d) + (%d) + (%d) + (%d) + (%d) = %d\n", a, b, c, d, e, sum(5, a, b, c, d, e));

	return 0;
}