#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int c;
	scanf("%d", &c);

	for (int i = 2; i <= (int)sqrt((int)c); ++i) {
		if (c % i == 0) {
			printf("��Ϊ %d%%%d=0������%d��������", c, i, c);
			return 0;
		}
	}

	printf("%d������", c);

	return 0;
}