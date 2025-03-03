#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Method1() {
	double profit = 0;	// 利润
	double bonus = 0; // 奖金

	if (scanf("%lf", &profit) != 1) {
		printf("input error");
		return -1;
	}

	if (profit < 10) // <10
		bonus += profit * 0.1;

	else if (profit < 20) // 10-20
		bonus += 10 * 0.1 + (profit - 10) * 0.075;

	else if (profit < 40) // 20-40
		bonus += 10 * 0.1 + 10 * 0.075 + (profit - 20) * 0.05;

	else if (profit < 60) // 40-60
		bonus += 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + (profit - 40) * 0.03;

	else if (profit < 100) // 60-100
		bonus += 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + 20 * 0.03 + (profit - 60) * 0.015;

	else if (profit > 100) // >100
		bonus += 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + 20 * 0.03 + 40 * 0.015 + (profit - 100) * 0.01;

	printf("利润：%lf，奖金：%lf\n", profit, bonus);
}

void Method2() {
	double profit = 0;	// 利润
	double bonus = 0; // 奖金

	double stage10 = 10 * 0.1;
	double stage20 = stage10 + 10 * 0.075;
	double stage40 = stage20 + 20 * 0.05;
	double stage60 = stage40 + 20 * 0.03;
	double stage100 = stage60 + 40 * 0.015;

	scanf("%lf", &profit);

	if (profit < 10) // <10
		bonus += profit * 0.1;

	else if (profit < 20) // 10-20
		bonus += stage10 + (profit - 10) * 0.075;

	else if (profit < 40) // 20-40
		bonus += stage20 + (profit - 20) * 0.05;

	else if (profit < 60) // 40-60
		bonus += stage40 + (profit - 40) * 0.03;

	else if (profit < 100) // 60-100
		bonus += stage60 + (profit - 60) * 0.015;

	else if (profit > 100) // >100
		bonus += stage100 + (profit - 100) * 0.01;

	printf("利润：%lf，奖金：%lf\n", profit, bonus);
}

int main() {
	Method1();
	Method2();

	return 0;
}