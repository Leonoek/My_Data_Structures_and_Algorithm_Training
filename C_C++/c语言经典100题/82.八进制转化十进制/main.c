#include <stdio.h>
#include <math.h>

void Method1() {
	char array[] = "123";
	int num = 0;
	int i = 0;

	while (array[i] != '\0') {
		num = num * 8 + array[i] - '0';
		++i;
	}
	printf("result: %d\n", num);
}

void Method2() {
	int target = 123;
	int num = 0;
	int i = 0;

	while (target % 10 != 0) {
		num += pow(8, i) * (target % 10);
		target = target / 10;
		++i;
	}
	printf("result: %d\n", num);
}

int main() {
	Method1();
	Method2();

	return 0;
}