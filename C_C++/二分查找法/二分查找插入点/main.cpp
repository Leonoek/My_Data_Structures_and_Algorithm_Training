#include <iostream>

namespace Method1 {
	int BinarySearchInsertionSimple(int* array, int target, int len) {
		int i = 0, j = len - 1, mid = 0;

		while (i <= j) {
			mid = (i + j) / 2;

			if (target > array[mid]) i = mid + 1;
			else if (target < array[mid]) j = mid - 1;
			else return mid;
		}
		return i;
	}

	void UseCase() {
		int array[] { 1, 3, 4, 5, 17, 30 };
		int result = BinarySearchInsertionSimple(array, 5, sizeof(array) / sizeof(array[0]));
		std::cout << "insert sit is :" << result << std::endl;
	}
}

int main() {
	Method1::UseCase();
	return 0;
}