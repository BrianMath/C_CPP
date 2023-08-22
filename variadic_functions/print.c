#include <stdio.h>
#include <stdarg.h>
#include <string.h>


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

void print(char* string, ...) {
	va_list args;
	va_start(args, string);

	unsigned int tam = strlen(string);
	
	for (int i = 0; i < tam; i++) {
		char* c = &string[i];
		
		if (*c == '+') {
			*c++;

			// int
			if (*c == 'd') {
				char buffer[20];
				int num = va_arg(args, int);
				
				sprintf(buffer, "%d", num);
				fputs(buffer, stdout);

				i++;
			}
			// float
			else if (*c == 'f') {
				char buffer[50];
				float num = (float) va_arg(args, double);
				
				sprintf(buffer, "%f", num);
				fputs(buffer, stdout);

				i++;
			}
			// double
			else if (*c == 'l' && *(c+1) == 'f') {
				char buffer[350];
				double num = (double) va_arg(args, double);
				
				sprintf(buffer, "%lf", num);
				fputs(buffer, stdout);

				i += 2;
			}
			// char
			else if (*c == 'c') {
				char ch = (char) va_arg(args, int);
				putchar(ch);

				i++;
			}
			// string
			else if (*c == 's') {
				char* str = va_arg(args, char*);
				fputs(str, stdout);

				i++;
			}
		} else {
			if (*c == '\\' && *(c+1) == 'n') {
				putchar('\n');
				i++;
			} else {
				putchar(*c);
			}
		}
	}

	putchar('\n');
	
	va_end(args);
}


int main() {
	// printf("Soma: %d\n", sum(3, 1, 1, 1));
	// teste(3, 1, 3.14, "Olá, mundo!");
	print("oi +d +f +lf +c ", 1, 2.0, -3.14+1, 'a');
	print("*s", "Olá, mundo!");
	// printf("\n\noi\n", 4);
	

	return 0;
}
