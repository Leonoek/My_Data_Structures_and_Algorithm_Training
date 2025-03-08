#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int c;
	scanf("%d", &c);

	for (int i = 2; i <= (int)sqrt((int)c); ++i) {
		if (c % i == 0) {
			printf("因为 %d%%%d=0，所以%d不是质数", c, i, c);
			return 0;
		}
	}

	printf("%d是质数", c);

	return 0;
}