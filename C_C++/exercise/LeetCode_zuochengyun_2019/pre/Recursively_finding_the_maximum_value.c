/*
递归求数组中的最大值，
时间复杂度：O(N longn)
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int process(int* input_array, int head, int end){
    if (head == end)
    {
        return input_array[head];
    }
    
    int mid = head + (end - head) / 2;
    int a = process(input_array, head, mid);
    int b = process(input_array, mid + 1, end);
    return a > b ? a : b;
}

int start(int* input_array, int array_num){
    return process(input_array, 0, array_num - 1);
}

int main() {
    srand((unsigned)time(NULL));
    
    int array_num = (rand() % 10);
    int intput_array[array_num];
    for (int i = 0; i < array_num; i++)
    {
        intput_array[i] = rand() % 100;
        printf("%d\n", intput_array[i]);
    }
    
    int result = start(intput_array, array_num);
    printf("max is: %d\n", result);
    
    return 0;
}