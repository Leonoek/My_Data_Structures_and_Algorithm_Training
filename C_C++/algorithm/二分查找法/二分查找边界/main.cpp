#include <iostream>

namespace Method1 {
	/* 二分查找最左一个 target */
	int BinarySearchLeftEdge(int* nums, int numSize, int target) {
		int i = 0, j = numSize - 1, mid = 0;

		while (i <= j) {
			mid = (i + j) / 2;

			if (target > nums[mid]) {
				i = mid + 1;
			}
			else if (target < nums[mid]) {
				j = mid - 1;
			}
			else if(target == nums[mid]) {
				j = mid - 1;
			}
		}

		if (target == nums[i]) return i;
		else return -1;
	}

	void UseCaseLeftEdge() {
		int array[] { 1, 2, 4, 5, 5, 6, 8, 8, 8, 9, 10 };
		int result = BinarySearchLeftEdge(array, sizeof(array) / sizeof(array[0]), 4);
		if (-1 == result) std::cout << "error input" << std::endl;
		else std::cout << "sit is: " << result << std::endl;
	}

	/* 二分查找最right一个 target */
	int BinarySearchRightEdge(int* nums, int numSize, int target) {
		int i = 0, j = numSize - 1, mid = 0;

		while (i <= j) {
			mid = (i + j) / 2;

			if (target > nums[mid]) {
				i = mid + 1;
			}
			else if (target < nums[mid]) {
				j = mid - 1;
			}
			else if (target == nums[mid]) {
				i = mid + 1;
			}
		}

		if (target == nums[j]) {
			return j;
		}
		else return -1;
	}

	void UseCaseRightEdge() {
		int array[]{ 1, 2, 4, 5, 5, 6, 8, 8, 8, 9, 10 };
		int result = BinarySearchRightEdge(array, sizeof(array) / sizeof(array[0]), 4);
		if (-1 == result) std::cout << "error input" << std::endl;
		else std::cout << "sit is: " << result << std::endl;
	}
};

int main() {
	Method1::UseCaseRightEdge();
	Method1::UseCaseLeftEdge();
	return 0;
}