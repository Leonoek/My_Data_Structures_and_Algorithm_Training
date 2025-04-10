/*
二分法求一个数组中的相邻数字各不相等，求出一个局部最小值
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* BinarySearch(int* array, int head, int end){
    int mid = (head + end) / 2;
    
    if (array[mid] > array[mid + 1])
    {
        return BinarySearch(array, mid + 1, end);
    }else// if (array[mid] < array[mid + 1])
    {
        if (array[mid] < array[mid - 1])
        {
            return array + mid;
        }else
        {
            return BinarySearch(array, head, mid - 1);
        }
    }
}

int* find(int* array, int array_num){
    if (array_num == 0)
    {
        return NULL;
    }

    if (array_num == 1)
    {
        return array;
    }
    
    if (array[0] < array[1])
    {
        return array;
    }else if (array[array_num - 1] < array[array_num - 2])
    {
        return array + array_num - 1;
    }else
    {
        return BinarySearch(array, 0, array_num - 1);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int array_num = (rand() % 10);
    int input_array[array_num];

    int i = 0;
    while (i < array_num)
    {
        input_array[i] = rand() % 100;
        if (i != 0 && input_array[i] == input_array[i - 1])
        {
            continue;
        }
        printf("num: %d\n", input_array[i]);
        ++i;
    }
    
    int* result = find(input_array, array_num);
    if (result == NULL)
    {
        printf("no min val\n");
        return(EXIT_FAILURE);
    }
    
    printf("min val is: %d", *result);
    
    return 0;
}