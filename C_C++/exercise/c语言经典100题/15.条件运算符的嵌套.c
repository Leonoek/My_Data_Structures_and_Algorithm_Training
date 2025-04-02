#include <stdio.h>

int main() {
	int target = 69;
	char goal = target >= 90 ? 'A' : (target >= 60 ? 'B' : 'C');
	printf("%c", goal);

	return 0;
}