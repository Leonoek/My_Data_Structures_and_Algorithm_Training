#include <stdio.h>

int main() {
	const int A = 15;
	const int B = 18;
	int a = A;
	int b = B;
	int r;

	r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	int c = A / b;
	int d = B / b;

	printf("最大公约数是：%d，最小公倍数是：%d", b, c * d * b);

	return 0;
}