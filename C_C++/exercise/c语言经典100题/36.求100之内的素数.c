#include <stdio.h>
#include <math.h>

int Prime(int x) {
	if (x <= 0) return 0;
	if (x == 1) return 0;
	if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	for (int i = 3; i <= (int)sqrt((double)x); ++i) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int Go(int x) {
	if (Prime(x) == 1) printf("%d\t", x);
}

int main() {
	for (int i = 1; i <= 100; ++i) {
		Go(i);
	}

	return 0;
}