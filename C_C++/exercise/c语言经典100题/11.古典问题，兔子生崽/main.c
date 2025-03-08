#include <stdio.h>

int main() {
	long long int a = 1;
	long long int b = 1;

	
	for (int i = 1; i <= 20; ++i) {
		printf("%12lld%12lld", a, b);
		if (i % 2 == 0) {
			printf("\n");
		}
		a += b;
		b += a;
	}


	return 0;
}