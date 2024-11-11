#include <stdio.h>
char *str1 = "Digite um número: "; int main() { int num; asm("movq $str1, %rdi\n movl 0, %eax\n call printf\n"); return scanf("%d", &num), num *= 2, printf("O dobro do número informado é %d\n", num), 0; }
