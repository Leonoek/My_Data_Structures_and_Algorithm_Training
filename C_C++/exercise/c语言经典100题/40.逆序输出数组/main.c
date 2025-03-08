#include <stdio.h>

int main() {
	//int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int array_len = sizeof(array) / sizeof(int);
	int temp = 0;

	for (int i = 0; i < array_len / 2; ++i) {
		temp = array[i];
		array[i] = array[array_len - 1 - i];
		array[array_len - 1 - i] = temp;
	}

	for (int i = 0; i < array_len; ++i) {
		printf("%-4d", array[i]);
	}

	return 0;
}