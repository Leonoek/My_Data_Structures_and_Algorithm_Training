#include <stdio.h>

int main() {
	int target = 123456;
	int k = 0;
	int b = 0;
	int sum = 0;

	while (target != 0) {
		k = target % 10;
		sum = sum * 10 + k;
		target = target / 10;
	}

	printf("%d\n", sum);

	return 0;
}