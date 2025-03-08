/*
The sum of two numbers equals the target value
两数之和等于需要的第三值
*/

#include <iostream>

namespace Method1 {
	int* TwoSumBruteForce(int* array, int len, int target) {
		for (int i = 0; i < len; ++i)
			for (int j = i + 1; j < len; ++j)
			{
				if (target == array[i] + array[j]) {
					int* sit = (int*)malloc(sizeof(int) * 2);
					if (sit == NULL) {
						return NULL;
					}
					*sit = i;
					*(sit + 1) = j;
					return sit;
				}
			}
		return NULL;
	}

	void UseCase() {
		int array[]{ 1, 3, 2, 5, 7, 8, 9, 10 };
		int* result = TwoSumBruteForce(array, sizeof(array) / sizeof(array[0]), 10);
		if (NULL == result) std::cout << "error input!" << std::endl;
		else std::cout << "find sit: " << *result << ", " << *(result + 1) << std::endl;
	}
}

int main() {
	Method1::UseCase();
	return 0;
}