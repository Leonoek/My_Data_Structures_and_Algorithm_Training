#include <stdio.h>
#include <string.h>

void Method1() {
	char array1[50] = "123548321121234512389123";
	char array2[5] = "123";
	int array1_len = strlen(array1);
	int array2_len = strlen(array2);
	int count = 0;

	int j;
	for (int i = 0; i < array1_len; ++i) {
		for (j = 0; j < array2_len; ++j) {
			if (*(array1 + i + j) != *(array2 + j)) {
				break;
			}
		}
		if (j == array2_len) {
			++count;
		}
	}

	printf("Method1:count: %d\n", count);
}

int main() {
	Method1();
	char array1[50] = "123548321121234512389123";
	char array2[5] = "123";
	int array1_len = strlen(array1);
	int array2_len = strlen(array2);
	int count = 0;

	for (int i = 0; i < array1_len; ++i) {
		if (strncmp(array1 + i, array2, array2_len) == 0) {
			++count;
			i += 2;
		}
	}

	printf("Method2:count: %d\n", count);

	return 0;
}