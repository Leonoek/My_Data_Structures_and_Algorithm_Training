#include <stdio.h>

void Method1() {
	printf("Method1:\n");
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int array_len = sizeof(array) / sizeof(int);
	int* array_ptr;
	int temp;
	int m = 4;	// times

	for (int i = 0; i < m; ++i) {
		array_ptr = array + array_len - 1;
		temp = *(array + array_len - 1);
		while (array_ptr > array) {
			*array_ptr = *(array_ptr - 1);
			--array_ptr;
		}
		*array = temp;
	}

	for (int i = 0; i < array_len; ++i) {
		printf("%-4d", array[i]);
	}
	printf("\n");
}

void Method2() {
	printf("Method2:\n");
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int array_len = sizeof(array) / sizeof(int);
	int* arrayptr = array + array_len - 1;

	int m = 4;	// times
	int temp_array[50] = { 0 };

	// 提取并存放到暂存区
	int loop_temp = 0;
	for (int i = array_len - 4; i < array_len; ++i) {
		temp_array[loop_temp] = array[i];
		++loop_temp;
	}

	// 原来的数组移动m个位置
	for (int i = 0; i < array_len - m; ++i) {
		array[array_len - i - 1] = array[array_len - 1 - m - i];
	}

	for (int i = 0; i < m; ++i) {
		array[i] = temp_array[i];
	}

	// 暂存的数组替换原来的数组的相应位置
	printf("result: ");
	for (int i = 0; i < array_len; ++i) {
		printf("%-4d", array[i]);
	}

	printf("\n");

	printf("temp array: ");
	for (int i = 0; i < 50; ++i) {
		if (temp_array[i] == '\0') {
			break;
		}
		printf("%-4d", temp_array[i]);
	}
}

int main() {
	Method1();
	Method2();

	return 0;
}