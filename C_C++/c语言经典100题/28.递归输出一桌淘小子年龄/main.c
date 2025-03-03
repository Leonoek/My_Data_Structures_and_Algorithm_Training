#include <stdio.h>

int Func(int n) {
	if (n == 1) {
		return 10;
	}
	else {
		return Func(n - 1) + 2;
	}
}

int main() {
	int result = Func(5);
	printf("%d", result);

	return 0;
}