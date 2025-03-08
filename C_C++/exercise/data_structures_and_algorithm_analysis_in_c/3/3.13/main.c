#include <stdio.h>
#include "ordinal_sorting.h"
#define SIZE(x) (sizeof(x) / sizeof(x[0]))
#define DIGIT 7
#define BUCKET_NUM 1000

int main(int argc, char *argv[])
{
    const int* result;
    int my_array[] = {1, 10256, 666666, 7777777, 15, 452, 127, 856, 7894};
    result = sort(my_array, SIZE(my_array), DIGIT, BUCKET_NUM);

    return 0;
}