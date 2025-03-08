#include <stdio.h>


int main() {
	int x = 0, m = 0, n = 0, j = 0;

	for (int i = 2; i < 168 / 2 + 1; i += 2) {
		if (168 % i == 0) {
			j = 168 / i;

			if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0) {
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n * n - 100;
				printf("x£º%d\n", x);
				printf("%d + 100 = %d, %d + 100 + 168 = %d\n", x, n * n, x, m * m);
				printf("\n");
			}
		}
	}
	return 0;
}