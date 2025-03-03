#include <stdio.h>

int main() {
	for (char a = 'x'; a <= 'z'; ++a) {
		for (char b = 'x'; b <= 'z'; ++b) {
			for (char c = 'x'; c <= 'z'; ++c) {
				if (a != b && a != c && b != c && a != 'x' && c != 'x' && c != 'z') {
					printf("a: %c, b: %c, c: %c", a, b, c);
				}
			}
		}
	}

	return 0;
}