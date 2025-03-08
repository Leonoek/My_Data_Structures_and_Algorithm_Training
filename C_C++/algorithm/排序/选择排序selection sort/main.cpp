#include <iostream>

namespace Method1{
	void SelectionSort(int* array, int len) {
		int min = 0;
		for (size_t i = 0; i < len - 1; i++)
		{
			min = i;
			for (size_t j = i + 1; j < len; j++)
			{
				if (array[min] > array[j]) min = j;
			}
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}

	void UseCase() {
		int array[]{ 9, 15, 4, 8, 9, 5, 3, 10, 23 };
		SelectionSort(array, sizeof(array) / sizeof(int) - 1);
		for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		{
			std::cout << array[i] << std::endl;
		}
	}
}

int main() {
	Method1::UseCase();
	return 0;
}