#include <stdio.h>

void Func(int number) {
	char c;
	if (number == 1) {
		c = getchar();
		putchar(c);
	}
	else {
		c = getchar();
		Func(number - 1);
		putchar(c);
	}

}

int main() {
	Func(5);

	return 0;
}