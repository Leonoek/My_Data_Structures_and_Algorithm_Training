/*
递归求数组中的最大值，
时间复杂度：O(N)
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int* input_array, int head, int mid, int end){
    int p1 = head;
    int p2 = mid + 1;
    int num = end - head + 1;
    int* new_array = malloc(sizeof(input_array) * num);
    int p_new_array = 0;
    while (p1 <= mid && p2 <= end)
    {
        if (input_array[p1] < input_array[p2])
        {
            new_array[p_new_array++] = input_array[p1++];
        }else
        {
            new_array[p_new_array++] = input_array[p2++];
        }
    }
    
    while (p1 <= mid)
    {
        new_array[p_new_array++] = input_array[p1++];
    }
    
    while (p2 <= end)
    {
        new_array[p_new_array++] = input_array[p2++];
    }

    for (int i = 0; i < num; i++)
    {
        int tmp = new_array[i];
        input_array[head++] = new_array[i];
    }
    free(new_array);
}

void process(int* input_array, int head, int end){
    if (head == end)
    {
        return;
    }
    
    int mid = head + (end - head) / 2;
    process(input_array, head, mid);
    process(input_array, mid + 1, end);
    merge(input_array, head, mid, end);
}

int main() {
    srand((unsigned)time(NULL));
    
    int array_num = (rand() % 10);
    if (array_num == 0)
    {
        return 0;
    }
    
    int intput_array[array_num];
    for (int i = 0; i < array_num; i++)
    {
        intput_array[i] = rand() % 100;
        printf("%d\n", intput_array[i]);
    }
    
    process(intput_array, 0, array_num - 1);

    printf("list is: ");
    for (int i = 0; i < array_num; i++)
    {
        printf("%5d", intput_array[i]);
    }
    
    
    return 0;
}