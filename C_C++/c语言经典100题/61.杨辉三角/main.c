#include <stdio.h>

#define width 10
#define height 10

int main() {

	int array[width][height] = {0};
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0) {
				array[i][j] = 1;
			}
		}
	}

	for (int i = 2; i < width; ++i) {
		for (int j = 1; j < i; ++j) {
			array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
		}
	}

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%-4d", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}