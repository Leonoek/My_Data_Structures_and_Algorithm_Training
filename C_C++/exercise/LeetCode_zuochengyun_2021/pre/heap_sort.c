/*
堆排序

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* array, int a, int b){
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void mysiftDown(int* array, int index, int num){
    int left;
    int right;
    int target;

    while (1)
    {
        left = index * 2 + 1;
        right = index * 2 + 2;
        target = index;

        if (left < num && array[left] > array[target])
        {
            target = left;
        }

        if (right < num && array[right] > array[target])
        {
            target = right;
        }
        
        if (target == index)
        {
            break;
        }
        
        swap(array, target, index);
        index = target;
    }
}

void mysiftUp(int* array, int index){
    int parent;
    int target;

    while (1)
    {
        parent = (index - 1) / 2;
        target = index;

        if (parent > -1 && array[parent] < array[index])
        {
            target = parent;
        }
        
        if (target == index)
        {
            break;
        }
        
        swap(array, target, index);
        index = parent;
    }
}

void heap_sort1(int* input_array1, int array_num){
    for (int i = array_num / 2 - 1; i > -1; i--)
    {
        mysiftDown(input_array1, i, array_num);
    }

    printf("first shift down the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array1[i]);
    }

    for (int i = array_num - 1; i > 0; i--)
    {
        swap(input_array1, 0, i);
        mysiftDown(input_array1, 0, i);
    }
    
    printf("\nsecond shift down the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array1[i]);
    }
}

void heap_sort2(int* input_array, int array_num){
    for (int i = array_num - 1; i > 0; i--)
    {
        mysiftUp(input_array, i);
    }

    printf("\nfirst shift down the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array[i]);
    }

    for (int i = array_num - 1; i > 0; i--)
    {
        swap(input_array, 0, i);
        mysiftDown(input_array, 0, i);
    }
    
    printf("\nsecond shift down the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array[i]);
    }
}

int main(){
    srand((unsigned)time(NULL));
    int array_num = 9;
    while (!array_num)
    {
        array_num = (rand() % 10);
    }

    // int input_array1[array_num];
    // for (int i = 0; i < array_num; i++)
    // {
    //     input_array1[i] = rand() % 10;
    //     printf("%d ", input_array1[i]);
    // }
    // printf("\n");
    int input_array1[] = {0, 7, 7, 7, 9, 5, 2, 9, 8};
    heap_sort1(input_array1, array_num);

    int input_array2[] = {0, 7, 7, 7, 9, 5, 2, 9, 8};
    heap_sort2(input_array2, array_num);
    
    return 0;
}