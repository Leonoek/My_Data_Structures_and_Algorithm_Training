#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "heap.h"

int main(int argc, char *argv[])
{
    Myheap myheap = create();
    add(&myheap, 10);
    add(&myheap, 9);
    add(&myheap, 1);
    add(&myheap, 90);
    
    return 0;
}