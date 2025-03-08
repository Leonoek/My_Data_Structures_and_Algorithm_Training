#include <stdio.h>
#include <math.h>

int main() {
	int target = 4;
	int sum = 0;
	for (int i = 1; i <= 4; ++i) {
		if (i == 1) {
			sum += 4;
			printf("site 1 num is: %d\n", 4);
		}
		else if (i == 2) {
			sum += 4 * 7;
			printf("site 2 num is: %d\n", 4 * 7);
		}
		else {
			sum += 4 * pow(8, i - 2) * 7;
			printf("site %d num is: %d\n", i, 4 * (int)pow(8, i - 2) * 7);
		}
	}

	printf("sum is %d", sum);

	return 0;
}