#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char play = 'y';

void Func() {
	int target = 50;
	int num = 0;
	int count = 0;

	while (1) {
		++count;
		printf("please input num:");
		scanf("%d", &num);
		if (num == target) {
			printf("you are right!\n");
			printf("played count: %d\n", count);
			break;
		}
		else if (num < target) {
			printf("small\n");
		}
		else {
			printf("Large\n");
		}
	}
}

int main() {
	while (play == 'y' || play == 'Y'){
		Func();
		printf("play again?");
		getchar();
		scanf("%c", &play);
	}
	
	return 0;
}