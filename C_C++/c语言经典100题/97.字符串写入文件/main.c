#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* f = NULL;
	char a;
	f = fopen("test.txt", "r+");
	//while ((a = fgetc(f)) != EOF) {
	//	printf("%c", a);
	//}

	printf("\nplease input:");
	while ((a = getchar()) != '#') {
		fputc(a, f);
	}

	fclose(f);

	return 0;
}