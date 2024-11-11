#include <stdio.h>

int even(int n) {
	return n % 2 == 0;
}

void print_even(int n) {
	printf("%d is even\n", n);
}

void print_odd(int n) {
	printf("%d is odd\n", n);
}

int main() {
	int num = 0;
	scanf("%d", &num);

	switch (num) {
		default:
			if (even(num)) {
				case 0: case 2: case 4: case 6:
					print_even(num);
			} else {
				case 1: case 3: case 5: case 7:
					print_odd(num);
			}
	}

	return 0;
}
