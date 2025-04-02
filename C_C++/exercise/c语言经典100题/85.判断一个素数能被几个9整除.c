#include <stdio.h>

int main() {
	int target = 9;
	int prime = 9;
	while (prime % target != 0) {
		prime = prime * 10 + 9;
	}

	printf("%d\n", prime);

	return 0;
}