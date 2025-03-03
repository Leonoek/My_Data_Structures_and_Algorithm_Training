//输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。
#include <stdio.h>

int main() {
	int array[] = { 5, 8, 3, 4, 9, 6, 7 };
	int array_len = sizeof(array) / sizeof(int);

	int min_val = array[0];
	int min = 0;

	int max_val = array[0];
	int max = 0;

	int temp = 0;

	for (int i = 0; i < array_len; ++i) {
		if (array[i] < min_val) {
			min_val = array[i];
			min = i;
		}

		if (array[i] > max_val) {
			max_val = array[i];
			max = i;
		}
	}

	temp = array[max];
	array[max] = array[0];
	array[0] = temp;

	temp = array[min];
	array[min] = array[array_len - 1];
	array[array_len - 1] = temp;

	for (int i = 0; i < array_len; ++i) {
		printf("%-4d", array[i]);
	}

	return 0;
}