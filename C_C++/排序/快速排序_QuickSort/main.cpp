#include <iostream>

namespace Method1 {
	int usecase_array[]{ 4, 12, 30, 2, 1, 0, 20};

	void ArrayLog() {
		for (size_t i = 0; i < sizeof(usecase_array) / sizeof(int); i++)
		{
			std::cout << usecase_array[i] << std::endl;
		}
	}

	int Mid(int* array, int low, int high) {
		int select = array[low];

		std::cout << std::endl;
		std::cout << "low is: " << low << ", high is: " << high << std::endl;
		ArrayLog();
		std::cout << std::endl;

		while (low < high) {
			std::cout << "inside while, low is: " << low << ", high is: " << high << std::endl;
			while ((low < high) && (array[high] > select)) {
				--high;
				ArrayLog();
				std::cout << "******************" << std::endl;
			}

			array[low] = array[high];

			while ((low < high) && (array[low] < select))
			{
				++low;
				ArrayLog();
				std::cout << "++++++++++++++++++" << std::endl;
			}
			array[high] = array[low];

		}
		array[low] = select;
		return low;
	}

	void QuickSort(int* array, int low, int high) {
		if (low < high)
		{
			int mid = Mid(array, low, high);
			QuickSort(array, low, mid - 1);
			QuickSort(array, mid + 1, high);
		}
	}

	void UseCase() {
		QuickSort(usecase_array, 0, (sizeof(usecase_array) / sizeof(int) - 1));
		ArrayLog();
	}
}

namespace Method2 {

	int partition(int a[], int low, int high) {
		int pivot = a[low];
		while (low < high) {
			while (low < high && a[high] >= pivot)
				high--;
			a[low] = a[high];
			while (low < high && a[low] <= pivot)
				low++;
			a[high] = a[low];
		}
		a[low] = pivot;
		return low;
	}

	void quickSort(int a[], int low, int high) {
		if (low < high) {
			int pos = partition(a, low, high);
			quickSort(a, low, pos - 1);
			quickSort(a, pos + 1, high);
		}
	}

	int main() {
		int a[8] = { 50, 40, 70, 90, 80, 10, 20, 60 };
		int low = 0;
		int high = 7;
		quickSort(a, low, high);

		printf("快速排序的结果为： ");
		for (int i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");

		char c = getchar();
		return 0;
	}
}

int main() {
	//Method1::UseCase();
	Method2::main();
	return 0;
}