#include <stdio.h>

long long int Func(int target) {
	long long int result = 1;
	for (int i = 1; i <= target; ++i) {
		result *= i;
	}
	return result;
}

int main() {
	long long int result = 0;

	for (int i = 1; i <= 20; ++i) {
		result += Func(i);
	}

	printf("%lld", result);

	return 0;
}