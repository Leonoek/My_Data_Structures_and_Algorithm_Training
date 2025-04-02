#include <stdio.h>

int main() {
	int a, b, c, d, e;
	int target = 12321;

	a = target / 10000;
	b = target / 1000 % 10;
	c = target / 100 % 10;
	d = target / 10 % 10;
	e = target % 10;

	if (a == e && b == d) {
		printf("True\n");
	}
	else {
		printf("False\n");
	}


	return 0;
}