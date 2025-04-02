#include <stdio.h>

int main() {
	int array[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int sum = 0;

	for (int i = 0; i < 3; ++i) {
		sum += array[i][i];
	}

	printf("sum is: %d", sum);

	return 0;
}