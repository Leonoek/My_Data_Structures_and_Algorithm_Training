#include <stdio.h>

long long int Func(int target) {
	if (1 == target) {
		return 1;
	}
	else {
		return target * Func(target - 1);
	}
}

int main() {
	int result = Func(5);
	printf("%d", result);

	return 0;
}