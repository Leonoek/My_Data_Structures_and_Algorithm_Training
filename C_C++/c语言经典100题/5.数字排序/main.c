#include <stdio.h>

int main() {
	int a = 13, b = 15, c = 9;
	int sum = a + b + c;

	printf("smallest: %d\n", (a < b ? a : b) < c ? (a < b ? a : b) : c);
	printf("mid: %d\n", sum - ((a < b ? a : b) < c ? (a < b ? a : b) : c) - ((a > b ? a : b) > c ? (a > b ? a : b) : c));
	printf("largeest: %d\n", (a > b ? a : b) > c ? (a > b ? a : b) : c);


	return 0;
}