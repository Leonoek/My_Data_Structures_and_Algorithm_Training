#include <stdio.h>

int main() {
	float a = 2, b = 1, temp;
	float sum = 0;
	for (int i = 0; i < 20; ++i) {
		sum += a / b;
		temp = a;
		a = a + b;
		b = temp;
	}
	printf("%f", sum);

	return 0;
}