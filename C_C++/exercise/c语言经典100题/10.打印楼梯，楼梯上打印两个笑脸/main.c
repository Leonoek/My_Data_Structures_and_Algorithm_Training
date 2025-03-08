#include <stdio.h>

int main() {
	printf("**\n");

	for (int i = 1; i < 10; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("X");
		}
		printf("\n");
	}
	return 0;
}