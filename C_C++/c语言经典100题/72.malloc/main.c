#include <stdio.h>
#include <stdlib.h>

#define num 10

int main() {
	int* intptr = malloc(sizeof(int) * num);
	if (intptr == NULL) {
		return;
	}

	for (int i = 0; i < num; ++i) {
		*(intptr + i) = i;
	}

	for (int i = 0; i < num; ++i) {
		printf("%-4d", *(intptr + i));
	}

	printf("intptr address: %p\n", intptr);

	int *temp = realloc(intptr, sizeof(int) * (num + 3));
	if (temp == NULL) {
		return;
	}
	else {
		intptr = temp;
		temp = NULL;
	}
	printf("realloc intptr address: %p\n", intptr);

	for (int i = 0; i < (num + 3); ++i) {
		*(intptr + i) = i;
	}

	for (int i = 0; i < (num + 3); ++i) {
		printf("%-4d", *(intptr + i));
	}


	free(intptr);

	return 0;
}