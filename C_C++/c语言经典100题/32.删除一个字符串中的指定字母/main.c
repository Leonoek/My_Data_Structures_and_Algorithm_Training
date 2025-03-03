#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void Stage1() {
	char c = 'a';
	char string[] = "i have a dream that will be come true!";

	for (int i = 0; i < strlen(string); ++i) {
		if (string[i] == c) {
			for (int j = i; j < strlen(string); ++j) {
				string[j] = string[j + 1];
			}
		}
	}

	printf("Stage1: %s\n", string);
}

void Stage2() {
	char c = 'a';
	char string[] = "i have a dream that will be come true!";
	char* strptr = string;
	char* tempstr;

	for (int i = 0; i < strlen(string); ++i) {
		if (*strptr == c) {
			tempstr = strptr;
			for (int j = i; j < strlen(string); ++j) {
				*tempstr = *(tempstr + 1);
				++tempstr;
			}
		}
		++strptr;
	}

	printf("Stage2: %s\n", string);
}

void Stage3() {
	char c[] = "tgf";
	int c_len = strlen(c);
	char string[] = "qwerwasdzxcabcdtgf";
	printf("Stage3 original: %s\t", string);
	int string_len = strlen(string);

	char* strptr = string;
	char* tempstr;

	for (int i = 0; i < string_len; ++i) {
		if (strncmp(strptr, c, c_len) == 0) {
			tempstr = strptr;
			for (int j = 0; j < string_len - i - c_len; ++j) {
				*tempstr = *(tempstr + c_len);
				++tempstr;
			}

			for (int k = 0; k < c_len; ++k) {
				*tempstr = '\0';
				++tempstr;
			}
		}
		++strptr;
	}

	printf("Stage3: %s\n", string);
}

void Stage4() {
	char c = 'a';
	char string[] = "i have a dream that will be come true!";
	char* strptr = string;
	char* tempstr;
	char string_temp[100];
	char* string_tempptr = string_temp;

	for (int i = 0; i < strlen(string); ++i) {
		if (*strptr == c) {
			tempstr = strptr;
			strcpy(string_temp, string);
			string_tempptr += strptr - string;
			strcpy(string_tempptr, tempstr + 1);
			strcpy(string, string_temp);

			string_tempptr = string_temp;
		}
		++strptr;
	}

	printf("Stage4: %s\n", string);
}

void Stage5() {
	char c = 'a';
	char string[] = "i have a dream that will be come true!";
	char* strptr = string;
	char* tempstr;
	char string_temp[100];
	char* string_tempptr = string_temp;

	for (int i = 0; i < strlen(string); ++i) {
		if (*strptr == c) {
			tempstr = strptr;
			memcpy(string_temp, string, strlen(string));
			string_tempptr += strptr - string;
			memcpy(string_tempptr, tempstr + 1, strlen(string) - (strptr - string) + 1);
			memcpy(string, string_temp, strlen(string));

			string_tempptr = string_temp;
		}
		++strptr;
	}

	printf("Stage5: %s\n", string);
}

int main() {
	Stage1();
	Stage2();
	Stage3();
	Stage4();
	Stage5();

	return 0;
}