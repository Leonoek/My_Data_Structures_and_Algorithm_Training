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

	printf("���Լ���ǣ�%d����С�������ǣ�%d", b, c * d * b);

	return 0;
}