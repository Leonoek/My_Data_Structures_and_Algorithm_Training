#include <stdio.h>
#include <stdint.h>
//#include <float.h>
#include <math.h>

int main() {
	int num = 0;

	for (int a = 1; a < 5; ++a)
	{
		for (int b = 1; b < 5; ++b)
		{
			for (int c = 1; c < 5; ++c)
			{
				if (a != b && b != c && a != c) {
					printf("%d%d%d\n", a, b, c);
					++num;
				}
			}
		}
	}

	printf("num is : %d\n", num);
	return 0;
}