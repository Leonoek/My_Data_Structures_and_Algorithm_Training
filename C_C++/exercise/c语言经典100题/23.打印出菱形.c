#include <stdio.h>

int main() {
	int top = 5, button = 4;
	int width = 9;

	for (int a = 0; a < top; ++a) {
		for (int i = 0; i < width / 2 - a; ++i) {
			printf(" ");
		}

		for (int j = 0; j < 2 * a + 1; ++j) {
			printf("*");
		}
		printf("\n");
	}

	for (int b = 0; b < button; ++b) {
		for (int i = 0; i < 1 + b; ++i) {
			printf(" ");
		}

		for (int j = 0; j < width - 2 - 2 * b; ++j) {
			printf("*");
		}
		printf("\n");
	}


	return 0;
}