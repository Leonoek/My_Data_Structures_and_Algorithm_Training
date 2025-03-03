#include <iostream>

namespace Method1 {
	int BinarySearch(int* array, int target, int start, int end) {
		if (start > end) return -1;

		int mid = (start + end) / 2;
		if (array[mid] == target) return mid;
		if (target > array[mid])	BinarySearch(array, target, mid + 1, end);
		else BinarySearch(array, target, start, mid - 1);
	}

	void UseCase() {
		int array[] = { 1, 5, 8, 9, 10, 15, 20 };
		int result = BinarySearch(array, 15, 0, sizeof(array) / sizeof(array[0]) - 1);
		if (-1 == result) std::cout << "error input!" << std::endl;
		else std::cout << "sit is: " << result << std::endl;
	}
}

namespace Method2 {
	int BinarySearch(int* array, int target, int len) {
		int i = 0, j = len - 1, mid = 0;

		while (i <= j) {
			mid = (i + j) / 2;
			if (target > array[mid]) i = mid + 1;
			else if (target < array[mid]) j = mid - 1;
			else if (target == array[mid]) return mid;
		}
		return -1;
	}

	void UseCase() {
		int array[] = { 1, 5, 8, 9, 10, 15, 20 };
		int result = BinarySearch(array, 12, sizeof(array) / sizeof(array[0]));
		if (-1 == result) std::cout << "error input!" << std::endl;
		else std::cout << "sit is: " << result << std::endl;
	}
}


int main() {
	Method2::UseCase();
	Method1::UseCase();

	return 0;
}