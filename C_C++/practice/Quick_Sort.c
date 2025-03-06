/*
递归排序

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void myswap(int* array, int position_x, int position_y){
    int x = array[position_x];
    array[position_x] = array[position_y];
    array[position_y] = x;
}

/* 哨兵划分 */
int partition(int nums[], int left, int right) {
    // 以 nums[left] 为基准数
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            j--; // 从右向左找首个小于基准数的元素
        }
        while (i < j && nums[i] <= nums[left]) {
            i++; // 从左向右找首个大于基准数的元素
        }
        // 交换这两个元素
        myswap(nums, i, j);
    }
    // 将基准数交换至两子数组的分界线
    myswap(nums, i, left);
    // 返回基准数的索引
    return i;
}

int merge(int* array, int head, int target, int end){
    myswap(array, target, end);
    int p1 = head;
    int p2 = end - 1;

    if (p1 == p2)
    {
        if (array[p1] > array[end])
        {
            myswap(array, p1, end);
        }
        return p1;
    }

    while (p1 < p2)
    {
        while (array[p1] < array[end] && p1 < end)
        {
            ++p1;
        }

        while (array[p2] > array[end] && p2 > head)
        {
            --p2;
        }

        if (p1 >= p2)
        {
            myswap(array, p1, end);
            return p1;
        }else if (p1 < p2)
        {
            if (array[p1] == array[end] && array[p2] == array[end])
            {
                myswap(array, p2 + 1, end);
                return p2 + 1;
            }else
            {
                myswap(array, p1, p2);
            }
        }
    }
}

void process(int* array, int head, int end){
    if (head >= end)
    {
        return;
    }

    int select_sit = head + rand() % (end - head);
    int board = merge(array, head, select_sit, end);
    process(array, head, board - 1);
    process(array, board + 1, end);
}

int main(){
    srand((unsigned)time(NULL));
    int array_num = rand() % 10;
    while (!array_num)
    {
        array_num = (rand() % 10);
    }

    int input_array[array_num];
    for (int i = 0; i < array_num; i++)
    {
        input_array[i] = rand() % 10;
        printf("%d ", input_array[i]);
    }
    printf("\n");
    process(input_array, 0, array_num - 1);

    // 对数器
    int input_array2[array_num];
    memcpy(input_array2, input_array, array_num);
    partition(input_array2, 0, array_num - 1);
    
    int result = memcmp(input_array, input_array2, array_num);
    if (result != 0)
    {
        printf("error!\n");
    }
    

    printf("the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array[i]);
    }
    return 0;
}