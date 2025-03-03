#include <stdio.h>

int main() {
	int g, s, b;
	int target = 123;

	g = target % 10;
	s = target % 100 / 10;
	b = target / 100;

	if (b != 0) {
		printf("number is: %d%d%d\n", b, s, g);
		printf("up side down is: %d%d%d\n", g, s, b);
	}
	else if (s != 0) {
		printf("number is: %d%d\n", s, g);
		printf("up side down is: %d%d\n", g, s);
	}
	else {
		printf("number is: %d\n", g);
		printf("up side down is: %d\n", g);
	}

	

	return 0;
}