#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void UseCase1() {
	printf("Format 1:\n");
	int target = 2;
	int temp = target;

	int loop = 5;
	int sum = 0;

	printf("s=");

	for (int i = 0; i < loop; ++i) {
		sum += temp;
		printf("%d+", temp);
		target = target * 10;
		temp = target + temp;
	}

	printf("\nsum is: %d\n", sum);
}

void UseCase2() {
	printf("\n");
	printf("Format 2:\n");
	int target = 2;
	int temp = target;

	int loop = 5;
	int sum = 0;

	printf("s=");

	for (int i = 0; i < loop; ++i) {
		sum += target;
		printf("%d+", target);
		target = target * 10 + temp;
	}

	printf("\nsum is: %d\n", sum);
}

void UseCase3() {
	printf("\n");
	printf("Format 3:\n");
	int target = 2;
	int temp = target;

	int loop = 5;
	int sum = 0;

	char str1[100] = { 0 };
	strcat(str1, "s=");
	char str_temp[10] = { 0 };

	for (int i = 0; i < loop; ++i) {
		sum += temp;
		itoa(temp, str_temp, 10);
		strcat(str1, str_temp);
		strcat(str1, "+");
		target = target * 10;
		temp = target + temp;
	}

	int temp_var = strlen(str1);
	str1[strlen(str1) - 1] = '\0';

	printf("%s\n", str1);
	printf("sum is: %d\n", sum);
}

void UseCase4() {
	printf("\n");
	printf("Format 4:\n");
	int target = 2;
	int temp = target;

	int loop = 5;
	int sum = 0;

	char str1[100] = { 0 };
	strcat(str1, "s=");
	char str_temp[10] = { 0 };

	for (int i = 0; i < loop; ++i) {
		sum += temp;
		sprintf(str_temp, "%d", temp);
		strcat(str1, str_temp);
		strcat(str1, "+");
		target = target * 10;
		temp = target + temp;
	}

	int temp_var = strlen(str1);
	str1[strlen(str1) - 1] = '\0';

	printf("%s\n", str1);
	printf("sum is: %d\n", sum);
}

int main() {
	UseCase1();
	
	UseCase2();

	UseCase3();

	UseCase4();

	return 0;
}