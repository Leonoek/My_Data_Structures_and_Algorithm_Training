#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char c;
	
	int letter = 0;
	int space = 0;
	int number = 0;
	int other = 0;


	while ((c = getchar()) != '\n') {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			++letter;
		}
		else if (c >= 0 && c <= 0) {
			++number;
		}
		else if (c == ' ') {
			++space;
		}
		else {
			++other;
		}
	}

	printf("letter :%d, space: %d, number: %d, other: %d", letter, space, number, other);

	return 0;
}