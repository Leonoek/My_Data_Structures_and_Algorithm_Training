#include <iostream>

namespace Method1{
	int array[]{ 1, 6, 3, 4, 10, 9, 2 };

	void InsertionSort(int* array, int size) {
		int temp = 0, sit = 0;
		for (int i = 1; i < size; ++i)
		{
			sit = i;
			for (int j = i - 1; j >= 0; --j)
			{
				if (array[sit] > array[j]) break;
				else {
					temp = array[j];
					array[j] = array[sit];
					array[sit] = temp;
					--sit;
				}
			}
		}
	}

	void UseCase() {
		InsertionSort(array, sizeof(array) / sizeof(int));
		for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
		{
			std::cout << array[i] << std::endl;
		}
	}
}

int main() {
	Method1::UseCase();
	return 0;
}