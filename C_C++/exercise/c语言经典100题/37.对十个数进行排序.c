#include <stdio.h>

int main() {
	int num[] = { 6, 1, 4, 0, 3, 7, 8, 2, 5, 9 };
	int numlen = sizeof(num) / sizeof(num[0]);
	int temp = 0;

	for (int i = 0; i < numlen - 1; ++i) {
		for (int j = 0; j < numlen - i - 1; ++j) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}
	}


	for (int i = 0; i < numlen; ++i) {
		printf("%d", i);
	}

	return 0;
}