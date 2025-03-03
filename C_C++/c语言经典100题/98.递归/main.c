#include <stdio.h>

char Func(int n, char a, char b, char c) {
	// a
	if (n == 1) {
		printf("%c----->%c\n", a, c);
	}
	else {
		Func(n - 1, a, c, b);
		printf("%c----->%c\n", a, c);
		Func(n - 1, b, a, c);
	}
}

int main() {
	char a = 'a';
	char b = 'b';
	char c = 'c';
	Func(3, a, b, c);


	return 0;
}