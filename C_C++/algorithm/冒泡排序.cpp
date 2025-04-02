#include <iostream>

namespace Method1{
	void BubbleSort(int* array, int len) {
		int temp{ 0 };
		bool flag{ false };
		for (size_t i = len; i > 0; --i)
		{
			flag = false;
			for (size_t j = 0; j < i; ++j) {
				if (array[j] > array[j + 1])
				{
					flag = true;
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
			if (flag == false)	return;
		}
	}

	void UseCase() {
		int array[]{ 1, 19, 4, 0, 21, 5, 7, 6 };
		int len = sizeof(array) / sizeof(int) - 1;

		BubbleSort(array, len);
		for (size_t i = 0; i < len; i++)
		{
			std::cout << array[i] << std::endl;
		}
	}

}

int main() {
	Method1::UseCase();
	return 0;
}