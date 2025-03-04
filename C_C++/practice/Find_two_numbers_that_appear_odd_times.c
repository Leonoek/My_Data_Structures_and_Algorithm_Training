/*
寻找两个出现奇数次的数字
*/
#include <stdio.h>

int main() {
    int intput_array[] = {57, 57, 94, 32, 32, 32};
    int tmp = 0, output1 = 0;
    int result1 = 0, result2 = 0;
    for (int i = 0; i < sizeof(intput_array) / sizeof(intput_array[0]); i++)
    {
        tmp ^= intput_array[i];
    }
    
    output1 = tmp&(~tmp + 1);
    
    int arr_tmp;
    for (int i = 0; i < sizeof(intput_array) / sizeof(intput_array[0]); i++)
    {
        arr_tmp = intput_array[i];
        if ((output1 & arr_tmp) == 0)
        {
            result1 ^= intput_array[i];
        }
    }

    result2 = result1 ^ tmp;
    printf("result1: %d, result2: %d\n", result1, result2);
    
    return 0;
}