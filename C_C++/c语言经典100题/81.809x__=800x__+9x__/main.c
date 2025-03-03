#include <stdio.h>

int main() {
	for (int i = 10; i < 100; ++i) {
		if (809 * i > 999 && 809 * i < 10000 && 8 * i < 100 && 9 * i >= 100)
		if ((809 * i) == (800 * i + 9 * i)) {
			printf("%d * %d = %d + %d\n", 809 , i , 800 * i , 9 * i);
		}
	}

	return 0;
}