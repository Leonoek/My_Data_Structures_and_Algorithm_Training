#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int MAX_SIZE{ 10 };

typedef struct Pair {
	int key;
	char* value;
};

typedef struct ArrayHashMap {
	int num;
	Pair* buckets[MAX_SIZE];
};

int HashFunc(int key) {
	return key % MAX_SIZE;
}

ArrayHashMap* InitArrayHashMap() {
	ArrayHashMap* hashMap = (ArrayHashMap*)malloc(sizeof(ArrayHashMap));
	for (size_t i = 0; i < MAX_SIZE; ++i)
	{
		hashMap->buckets[i] = NULL;
	}
	hashMap->num = MAX_SIZE;
	return hashMap;
}

void DelArrayHashMap(ArrayHashMap* hashMap) {
	for (size_t i = 0; i < MAX_SIZE; ++i)
	{
		if (hashMap->buckets[i] != NULL)
		{
			 free(hashMap->buckets[i]->value);
			 free(hashMap->buckets[i]);
		}
		
	}
	free(hashMap);
}

int Put(ArrayHashMap* hashMap, const int key, const char *val) {
	// if hash map is full
	if (hashMap->num == 0) return -1;

	Pair* pair = (Pair*)malloc(sizeof(Pair));
	pair->key = key;
	pair->value = (char*)malloc(strlen(val) + 1);
	strcpy(pair->value, val);

	int index = HashFunc(key);

	while (hashMap->buckets[index] != NULL) {
		index = HashFunc(index + 1);
	}
	hashMap->buckets[index] = pair;
	--hashMap->num;
	return 1;
}

void Remove(ArrayHashMap* hashMap, const int key, const char* val) {
	int index = HashFunc(key);
	while (hashMap->buckets[index]->value != val) {
		index = HashFunc(index + 1);
	}
	hashMap->buckets[index]->key = 0;
	free(hashMap->buckets[index]->value);
	hashMap->buckets[index]->value = nullptr;
	free(hashMap->buckets[index]);
	hashMap->buckets[index] = nullptr;
}

void Print(ArrayHashMap* hashMap) {

	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		if (hashMap->buckets[i] == nullptr) continue;
		printf("key:%d, value:%s\n", hashMap->buckets[i]->key, hashMap->buckets[i]->value);
	}
}

int main() {
	ArrayHashMap* hashMap = InitArrayHashMap();
	int result = Put(hashMap, 114514, "hahah");
	if (-1 == result) printf("error put!");
	Print(hashMap);


	DelArrayHashMap(hashMap);

	return 0;
}