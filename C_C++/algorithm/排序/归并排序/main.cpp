//#include <stdio.h>
//#include <malloc.h>

#include <iostream>

int testarray[] = { 16, 13, 50, 20, 5, 7, 5, 4, 4, 10 };

void Merge(int* array, int low, int mid, int high) {
    int size = high - low + 1;
    //int* temp_array = (int*)malloc(sizeof(int) * size);
    int* temp_array = new int[size] {};
    if (!temp_array)
    {
        printf("p is null");
    }

    int x = 0, i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (array[i] <= array[j])
        {
            if (x >= size) return;  // avoide C6386 warning
            temp_array[x++] = array[i++];
        }
        else
        {
            if (x >= size) return;  // avoide C6386 warning
            temp_array[x++] = array[j++];
        }

    }

    while (i <= mid) {
        if (x >= size) return;  // avoide C6386 warning
        temp_array[x++] = array[i++];
    }

    while (j <= high) {
        if (x >= size) return;  // avoide C6386 warning
        temp_array[x++] = array[j++];
    }

    for (int i = 0; i < size; i++)
    {
        array[low + i] = temp_array[i];
    }

    //free(temp_array);
    delete[] temp_array;
}

void MergeSort(int* array, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    MergeSort(array, low, mid);
    MergeSort(array, mid + 1, high);
    Merge(array, low, mid, high);
}

void UseCase() {
    int num = sizeof(testarray) / sizeof(int);
    MergeSort(testarray, 0, num - 1);
    for (int i = 0; i < num; i++)
    {
        printf("%d\r\n", testarray[i]);
    }
}

int main() {
    UseCase();
    return 0;
}