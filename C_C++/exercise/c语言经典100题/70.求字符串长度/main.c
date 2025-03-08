#include <stdio.h>

int main() {
	//char string1[] = "hello world";
	char* string1 = "hello world";
	char* stringptr = string1;
	int count = 0;

	while (*stringptr != '\0') {
		++count;
		++stringptr;
	}

	printf("%d", count);

	return 0;
}