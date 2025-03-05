/*
小和问题
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int merge(int* array, int head, int mid, int end){
    int* tmp_array = malloc(sizeof(array) * (end - head + 1));
    int p1 = head, p2 = mid + 1, p_tmp = 0;
    int result = 0;
    int t_tmp;
    while (p1 <= mid && p2 <= end)
    {
        t_tmp = p2;
        while (array[p1] < array[t_tmp] && t_tmp <= end)
        {
            result += array[p1];
            ++t_tmp;
        }
        tmp_array[p_tmp++] = array[p1++];

        if (array[p1] >= array[p2])
        {
            tmp_array[p_tmp++] = array[p2++];
        }
    }
    
    while (p1 <= mid)
    {
        tmp_array[p_tmp++] = array[p1++];
    }
    
    while (p2 <= end)
    {
        tmp_array[p_tmp++] = array[p2++];
    }
    return result;
}

int process(int* array, int head, int end){
    if (head == end)
    {
        return 0;
    }
    
    int mid = head + (end - head) / 2;
    return process(array, head, mid) + process(array, mid + 1, end) + merge(array, head, mid, end);
}

int main(){
    srand((unsigned)time(NULL));
    int array_num = (rand() % 10);
    while (!array_num)
    {
        array_num = (rand() % 10);
    }
    int intput_array[array_num];
    for (int i = 0; i < array_num; i++)
    {
        intput_array[i] = rand() % 10;
        printf("%d ", intput_array[i]);
    }
    printf("\n");
    int result = process(intput_array, 0, array_num - 1);
    printf("min sum: %d\n", result);
    return 0;
}