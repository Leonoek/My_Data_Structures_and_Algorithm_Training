#include <iostream>

namespace Method1 {
	const int NUM{ 5 };
	typedef struct HashList{
		int num;
		int* data;
	} HashList, *pHashList;

	pHashList initList() {
		pHashList list = (pHashList)calloc(1, sizeof(HashList));
		if (NULL == list)
		{
			std::cout << "error init hash table!" << std::endl;
			exit(-1);
		}
		list->num = 0;
		list->data = (int*)calloc(NUM, sizeof(int));
		return list;
	}

	int Hash(int data) {
		return data % NUM;
	}

	void Put(pHashList list, int data) {
		int index = Hash(data);
		if (list -> data[index] != 0)
		{
			int count = 1;
			while (list -> data[index] != 0) {
				index = Hash(Hash(data) + count);
				count++;
			}
		}
		list->data[index] = data;
		++(list->num);
	}

	int Find(pHashList list, int target) {
		int sit = Hash(target);
		int times = 0;
		while (target != list->data[sit % NUM] && times <= list->num) {
			if (NULL == list->data[sit]) return -1;
			++sit;
			++times;
		}

		if (times > list->num) return -1;
		return Hash(sit);
	}

	void UseCase() {
		pHashList list = initList();
		Put(list, 'n');
		Put(list, 'p');
		Put(list, 'q');
		Put(list, 'm');
		Put(list, 'h');
		
		for (int i = 0; i < list->num; ++i) {
			printf("site: %d, %C\r\n", i, list->data[i]);
		}

		/* find */
		char target = 'h';
		int result = Find(list, target);
		if (result != -1) std::cout << "target " << target << "set: " << result << std::endl;
		else std::cout << "not found!" << std::endl;
		
	}
}

int main() {
	Method1::UseCase();
	return 0;
}