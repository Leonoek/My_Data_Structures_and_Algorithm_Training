#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string1[50] = "i am a ";
	char string2[50] = "teacher.";
	//strcat(string1, string2);
	//printf("strcat: %s\n", string1);

	char* str1 = (char*)malloc(strlen(string1) + strlen(string2) + 1);
	if (str1 == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1; // ÍË³ö³ÌÐò
	}

	strcpy(str1, string1);
	strcat(str1, string2);
	printf("%s\n", str1);
	return 0;
}