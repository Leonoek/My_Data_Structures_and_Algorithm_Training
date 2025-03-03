#include <stdio.h>

int main() {
	int target = 60;

	for (int i = 2; i <= target; i++)
	{
		while (target % i == 0) {
			printf("%4d", i);
			target = target / i;
		}
	}


	return 0;
}