/*
堆排序

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* array, int a, int b){
    array[a] ^= array[b];
    array[b] ^= array[a];
    array[a] ^= array[b];
}

void process1(int* array, int head, int end){
    int size = end - head + 1;
    int p = end;
    int parent;
    int tmp;
    while (p != head)
    {
        tmp = p;
        parent = (tmp - 1) / 2;
        while (array[tmp] > array[parent] && tmp != head)
        {
            swap(array, tmp, parent);
            tmp = parent;
            parent = (tmp - 1) / 2;
        }
        --p;
    }
}

int main(){
    srand((unsigned)time(NULL));
    int array_num = rand() % 10;
    while (!array_num)
    {
        array_num = (rand() % 10);
    }

    int input_array1[array_num];
    for (int i = 0; i < array_num; i++)
    {
        input_array1[i] = rand() % 10;
        printf("%d ", input_array1[i]);
    }
    printf("\n");

    // 对数器
    // int input_array2[array_num];
    // memcpy(input_array2, input_array1, array_num * sizeof(int));

    process1(input_array1, 0, array_num - 1);
    // process2(input_array2, 0, array_num - 1);
    
    // int result = memcmp(input_array1, input_array2, array_num);
    // if (result != 0)
    // {
    //     printf("error!\n");
    // }
    
    printf("the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array1[i]);
    }
    return 0;
}