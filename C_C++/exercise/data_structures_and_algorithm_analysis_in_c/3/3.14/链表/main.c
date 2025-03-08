#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define NUM_NODES 5
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

int main(int argc, char *argv[])
{
    Myheap temp;
    int input[] = {1, 3, 2, 4, 1, 6, 1, 7};
    int array_size = SIZE(input);
    Myheap myheap[NUM_NODES] = {0};

    for (int i = 0; i < array_size; i++)
    {
        if (i % 2 == 0)
        {
            add(&myheap[input[i]], input[i + 1]);
        }
    }



    
    return 0;
}