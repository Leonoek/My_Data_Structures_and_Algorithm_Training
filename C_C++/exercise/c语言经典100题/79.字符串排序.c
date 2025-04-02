#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(char* str1, char* str2) {
	char temp[30] = { 0 };
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

int main() {
	char string1[30] = "hada";
	char string2[30] = "jason";

	if (strcmp(string1, string2) > 0) {
		printf("string1 is bigger\n");
	}
	else {
		swap(string1, string2);
		printf("string2 is bigger\n");
	}

	printf("%s, %s\n", string1, string2);

	return 0;
}