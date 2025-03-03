#include <stdio.h>

int CompareNum(int target) {
	int sum = 0;

	for (int i = 1; i < target; ++i) {
		if (target % i == 0) {
			sum += i;
		}
	}

	if (sum == target) {
		//printf("%d is a wan shu\n", target);
		return 1;
	}
	else {
		//printf("%d is not a wan shu\n", target);
		return 0;
	}
}

int main() {
	for (int i = 1; i < 1000; ++i) {
		if (CompareNum(i)) {
			printf("%d\n", i);
		}
	}
	

	return 0;
}