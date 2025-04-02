#include <stdio.h>

int main() {
	double sum = 0, height = 100;

	sum = sum + height;	// first
	for (int i = 1; i < 10; ++i) {
		height = height / 2;
		sum += height * 2;
	}

	printf("sum: %f, height: %f", sum, height);

	return 0;
}