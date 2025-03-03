#include <stdio.h>

int main() {
	int day10 = 1;
	int day = day10;
	for (int i = 9; i > 0; --i) {
		day = (day + 1) * 2;
	}
	
	printf("total: %d", day);

	return 0;
}