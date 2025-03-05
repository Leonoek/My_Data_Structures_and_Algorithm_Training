/*
选定数组中的一个数，使得数组左边的数比这个数字小，数组右边的数比这个数字大

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void process(int* input_array, int len, int num){
    int p = 0;
    int left = -1;
    int right = len;
    int tmp_val;
    while (p < right)
    {
        if(num > input_array[p])
        {
            tmp_val = input_array[p];
            input_array[p] = input_array[left + 1];
            input_array[left + 1] = tmp_val;
            ++p;
            ++left;
        }
        else if(num < input_array[p])
        {
            tmp_val = input_array[p];
            input_array[p] = input_array[right - 1];
            input_array[right - 1] = tmp_val;
            --right;
        }
        else
        {
            ++p;
        }
    }
}

int main(){
    srand((unsigned)time(NULL));
    int array_num = rand() % 10;
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
    int number_middle = intput_array[rand() % array_num];
    printf("the num middel: %d\n", number_middle);
    
    process(intput_array, array_num, number_middle);

    printf("the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", intput_array[i]);
    }
    return 0;
}