#include <stdio.h>

void Method1() {
	char string[] = "1234567890";
	char temp;

	for (int i = 0; i < strlen(string) / 2; ++i) {
		temp = string[strlen(string) - 1 - i];
		string[strlen(string) - 1 - i] = string[i];
		string[i] = temp;
	}

	printf("Method1: %s\n", string);
}

void Method2() {
	char string[] = "1234567890";
	char* stringptr = string;
	char temp;

	for (int i = 0; i < strlen(string) / 2; ++i) {
		temp = *(stringptr + strlen(string) - 1 - i);
		*(stringptr + strlen(string) - 1 - i) = *(stringptr + i);
		*(stringptr + i) = temp;
	}

	printf("Method2: %s\n", string);
}

int main() {
	Method1();
	Method2();

	return 0;
}