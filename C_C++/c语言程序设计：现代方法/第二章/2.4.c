#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float v, count = 0;
	printf("please input count: \n");
	if (scanf("%f", &v) != 1) {
		printf("error!\n");
		return -1;
	}
	//count = v + v * 0.05;
	//printf("count is: %.2f\n", count);

	v = v + v * 0.05;
	printf("count is: %.2f\n", v);

	return 0;
}