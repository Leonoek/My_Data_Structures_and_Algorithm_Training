#include <stdio.h>

void Method1() {
	printf("Method1: ");
	int array[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	int array_len = sizeof(array) / sizeof(int);
	int site = 0;
	int num = 1;
	int leftover = array_len;

	while (leftover > 0) {
		if (site == array_len) {
			site = 0;
		}

		if (array[site] != 1) {
			++site;
			continue;
		}

		if (num == 3) {
			while (array[site] != 1) {
				++site;
				if (site == array_len) {
					site = 0;
				}
			}
			printf("%-4d", site + 1);
			array[site] = 0;
			num = 0;
			--leftover;
		}

		++site;
		++num;
	}
	printf("\n");
}

void Method2() {
	printf("Method2: ");
	int array[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	int array_len = sizeof(array) / sizeof(int);
	int site = 0;
	int num = 1;
	int count = array_len;

	while (count > 0) {
		while (array[site] != 1) {
			++site;
			if (site >= array_len) {
				site = 0;
			}
		}

		if (num == 3) {
			printf("%-4d", site + 1);
			array[site] = 0;
			num = 0;
			--count;
		}

		++site;
		++num;
	}
	printf("\n");
}

void Method3() {
	printf("Method3: ");
	int array[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1 };
	int array_len = sizeof(array) / sizeof(int);
	int site = 0;
	int num = 0;
	int count = array_len - 1;

	while (count > 0) {
		site++;
		num++;

		while (array[site] != 1) {
			++site;
			if (site > array_len) {
				site = 1;
				
			}
		}

		if (num == 3) {
			array[site] = 0;
			printf("%-4d", site);
			count--;
			num = 0;
			
		}

	}
	printf("\n");
}

int main() {
	Method1();
	Method2();
	Method3();
	
	return 0;
}