#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int year, month, day, sum;

	printf("please input year,month,day:");
	if (scanf("%d,%d,%d", &year, &month, &day) != 3 || year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		printf("input error!");
		return -1;
	}

	if (month == 2 && day > 29) {
		printf("input day error!");
		return -1;
	}

	switch (month) {
		case 1:
			sum = 0;
			break;
		case 2:
			sum = 31;
			break;
		case 3:
			sum = 59;
			break;
		case 4:
			sum = 90;
			break;
		case 5:
			sum = 120;
			break;
		case 6:
			sum = 151;
			break;
		case 7:
			sum = 181;
			break;
		case 8:
			sum = 212;
			break;
		case 9:
			sum = 243;
			break;
		case 10:
			sum = 273;
			break;
		case 11:
			sum = 304;
			break;
		case 12:
			sum = 334;
			break;
		default:
			printf("error!");
			return -1;
			break;
	}

	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		if (month > 2) {
			sum += 1;
		}
	}

	sum += day;

	printf("Total: %d", sum);

	return 0;
}