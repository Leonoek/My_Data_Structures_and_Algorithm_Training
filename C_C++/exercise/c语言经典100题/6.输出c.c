#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int width, height;
	
	printf("please input alpha \"c\" width and height\nhere is an example:10,20\n");
	if (scanf("%d,%d", &width, &height) != 2) {
		printf("error input!");
		return -1;
	}

	for (int i = 0; i < width; ++i) {
		printf("*");
	}
	printf("\n");

	for (int i = 0; i < height - 2; ++i) {
		printf("*\n");
	}

	for (int i = 0; i < width; ++i) {
		printf("*");
	}
	printf("\n");

	return 0;
}