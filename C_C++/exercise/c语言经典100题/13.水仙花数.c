#include <stdio.h>

int main() {
	int x, y, z;	// ��λ�� ʮλ�� ��λ

	for (int i = 100; i < 1000; ++i)
	{
		x = i % 10;
		y = i / 10 % 10;
		z = i / 100;

		if (i == (x * x * x + y * y * y + z * z * z)) {
			printf("%4d", i);
		}
	}


	return 0;
}