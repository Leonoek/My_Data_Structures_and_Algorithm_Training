//某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规则如下： 
//每位数字都加上5, 然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。

#include <stdio.h>

void Method1() {
	int target = 1234;
	int array[] = { target / 1000, target / 100 % 10, target / 10 % 10, target % 10 };
	for (int i = 0; i < 4; ++i) {
		array[i] += 5;
		array[i] %= 10;
	}
	int temp = 0;
	for (int i = 0; i < 2; ++i) {
		temp = array[i];
		array[i] = array[3 - i];
		array[3 - i] = temp;
	}

	for (int i = 0; i < 4; ++i) {
		printf("%d\n", array[i]);
	}
}

void Method2() {
	char array[] = "1234";
	for (int i = 0; i < 4; ++i) {
		array[i] = array[i] + 5 - '0';
		array[i] = array[i] % 10 + '0';
	}

	char temp[1] = {0};
	for (int i = 0; i < 2; ++i) {
		temp[0] = array[i];
		array[i] = array[3 - i];
		array[3 - i] = temp[0];
	}

	for (int i = 0; i < 4; ++i) {
		printf("%c ", array[i]);
	}

}

int main() {
	Method1();
	Method2();

	return 0;
}