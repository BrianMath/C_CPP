#include <stdio.h>
#include <stdarg.h>
#include <string.h>

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
	print("oi +d +f +lf +c ", 1, 2.0, -3.14+1, 'a');
	print("+s", "Olá, mundo!\n");

	return 0;
}
