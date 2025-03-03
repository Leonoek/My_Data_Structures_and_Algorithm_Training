#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int Prime(int x) {
	if (x < 2) {
		return 0;
	}
	else if (x == 2) {
		return 1;
	}
	else if (x % 2 == 0) {
		return 0;
	}
	else {
		for (int i = 3; i <= sqrt(x); ++i) {
			if (x % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int target;
	scanf("%d", &target);

	while (target % 2 != 0 || target < 4) {
		scanf("%d", &target);
	}

	for (int i = 2; i <= target / 2; ++i) {
		if (Prime(i) && Prime(target - i)) {
			printf("%d + %d = %d\n", i , target - i, target);
		}
	}

	

	return 0;
}