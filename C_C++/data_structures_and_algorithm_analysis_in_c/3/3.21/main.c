#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define ARRAY_SIZE 50

static int array[ARRAY_SIZE];
static int head;
static int end = ARRAY_SIZE - 1;

void head_add(int val);
void end_add(int val);
void head_empty();
void end_empty();

int main(int argc, char *argv[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        head_add(i);
    }
    
    head_empty();
    
    return 0;
}

void head_add(int val){
    if (head > end)
    {
        printf("func: %s, array full\n", __func__);
        exit(EXIT_FAILURE);
    }
    array[head++] = val;
}

void end_add(int val){
    if (head > end)
    {
        printf("func: %s, array full\n", __func__);
        exit(EXIT_FAILURE);
    }
    array[end--] = val;
}

void head_empty(){
    head = 0;
}

void end_empty(){
    end = 0;
}