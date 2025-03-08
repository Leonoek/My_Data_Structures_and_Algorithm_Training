#include <stdio.h>
#include <math.h>

int GetPrimeNumber_v1(int target) {
	for (int i = 2; i < target; ++i) {
		if (target % i == 0) {
			return 0;
		}
	}

	return 1;
}

int GetPrimeNumber_v2(int target) {
	int end = (int)sqrt((int)target);
	for (int i = 2; i <= end; ++i) {
		if (target % i == 0) {
			return 0;
		}
	}

	return 1;
}

void UseCase_v1() {
	int target = 7;
	if (GetPrimeNumber_v1(target) == 1) {
		printf("%d", target);
	}
	printf("\n");
}

void UseCase_v2() {
	int start = 101;
	int end = 200;

	for (int i = start; i <= end; ++i) {
		if (GetPrimeNumber_v1(i) == 1) {
			printf("%4d", i);
		}
	}

	printf("\n");
}

void UseCase_v3() {
	int start = 101;
	int end = 200;

	for (int i = start; i <= end; ++i) {
		if (GetPrimeNumber_v2(i) == 1) {
			printf("%4d", i);
		}
	}

	printf("\n");
}

int main() {
	UseCase_v1();
	UseCase_v2();
	UseCase_v3();

	return 0;
}