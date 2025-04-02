#include <stdio.h>

double Compute(int target) {
	double sum = 0;
	int i;

	if (target % 2 == 0) {
		i = 2;
	}
	else {
		i = 1;
	}

	for (; i <= target; i += 2) {
		sum += (double)1 / i;
	}
	return sum;
}

int main() {
	int target = 10;
	double (*p)(int) = &Compute;
	//double result = (*p)(target);
	double result = p(target);
	printf("input: %d, result: %lf", target, result);
	return 0;
}