#include <stdio.h>

int main() {
	int sum = 0, count = 1, result = 0;

	if (sum == 0)
		if (count == 0)
			result = 1;
	else					// if (count != 0), indentation doesn't matter
		result = 2;

	printf("result = %d\n", result);

	return 0;
}
