#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
    //int array1[11] = { 1, 5, 7, 9, 10, 14, 17, 28, 29, 32 };
    int array1[11] = { 32, 29, 28, 17, 14, 10, 9, 7, 5, 1 };
    int array1_len = sizeof(array1) / sizeof(int);
    int target = -1;

    for (int i = 0; i < array1_len - 1; ++i) {
        if (array1[i] < array1[i + 1]) {

            if (array1[array1_len - 2] < target) {
                array1[array1_len - 1] = target;
            }
            else {
                for (int j = 0; j < array1_len; ++j) {
                    if (array1[j] > target) {
                        for (int k = array1_len - 1; k >= j; --k) {
                            array1[k] = array1[k - 1];
                        }
                        array1[j] = target;
                        break;
                    }
                }
            }
        }
        else if (array1[i] > array1[i + 1]) {
            if (array1[array1_len - 2] > target) {
                array1[array1_len - 1] = target;
            }
            else {
                for (int j = 0; j < array1_len; ++j) {
                    if (array1[j] < target) {
                        for (int k = array1_len - 1; k >= j; --k) {
                            array1[k] = array1[k - 1];
                        }
                        array1[j] = target;
                        break;
                    }
                }
            }
        }
        else {
            continue;
        }
        break;
    }

    

    for (int i = 0; i < array1_len; ++i) {
        printf("%-5d", array1[i]);
    }

    return 0;
}