// Monday ����һ  Tuesday ���ڶ�   Wednesday ������  Thursday ������
// Friday ������  Saturday ������  Sunday ������

#include <stdio.h>
#include <ctype.h>

int main() {
	char c;

	c = tolower(getchar());
	switch (c)
	{
	case 'm':
		printf("Monday");
		break;

	case 't':
		c = getchar();
		if (c == '\n') {
			c = getchar();
		}

		if ((c == 'u' || c == 'U')) {
			printf("Tuesday");
		}
		else if ((c == 'h' || c == 'H')) {
			printf("Thursday");
		}
		else {
			printf("error input!\n");
			return -1;
		}
		break;

	case 'w':
		printf("Wednesday");
		break;

	case 'f':
		printf("Friday");
		break;

	case 's':
		c = getchar();
		if (c == '\n') {
			c = getchar();
		}

		if ((c == 'a' || c == 'A')) {
			printf("Saturday");
		}
		else if ((c == 'u' || c == 'U')) {
			printf("Sunday");
		}
		else {
			printf("error input!\n");
			return -1;
		}
		break;

			
	default:
		printf("error input!\n");
		break;
	}


	return 0;
}