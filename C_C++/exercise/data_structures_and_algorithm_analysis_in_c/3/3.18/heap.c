#include <stdlib.h>
#include <assert.h>

#include "heap.h"

struct heap
{
    int head;
    int capacity;
    Itemtype* item_array;
};

Myheap create(void){
    Myheap temp_heap = malloc(sizeof(struct heap));
    if (temp_heap == NULL)
    {
        return NULL;
    }
    
    Itemtype* temp_array = malloc(sizeof(Itemtype) * HEAP_ARRAY_SIZE);
    if (temp_array == NULL)
    {
        return NULL;
    }

    temp_heap->head = 0;
    temp_heap->capacity = HEAP_ARRAY_SIZE;
    temp_heap->item_array = temp_array;
}

/* 扩充 */
static void expansion(Myheap* my_heap){
    Itemtype* temp_array;
    temp_array = realloc((*my_heap)->item_array, sizeof(Itemtype) * (*my_heap)->capacity * 2);
    (*my_heap)->item_array = temp_array;
    (*my_heap)->capacity *= 2;
}

void add(Myheap* my_heap, Itemtype val){
    assert(my_heap != NULL);

    if ((*my_heap)->head == (*my_heap)->capacity)
    {
        expansion(my_heap);
    }
    (*my_heap)->item_array[(*my_heap)->head++] = val;
}

void delete(Myheap my_heap){
    assert(my_heap != NULL);
    free(my_heap->item_array);
    free(my_heap);
}

bool isempty(Myheap my_heap){
    return my_heap->head == 0;
}

bool isfull(Myheap my_heap){
    return my_heap->head == my_heap->capacity;
}

int pop(Myheap my_heap){
    Itemtype value;
    assert(my_heap != NULL);
    assert(!isempty(my_heap));
    // assert(!isfull(my_heap));

    value = my_heap->item_array[my_heap->head];
    --my_heap->head;
    return value;
}

void test(){
    int val;
    Myheap my_heap1;
    char* temp;
    char* input[] = {"/* */", "( )", "[ ]", "{ }"};
    my_heap1 = create();
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        temp = input[i];
        while (*temp != ' ')
        {
            add(&my_heap1, *temp);
            ++temp;
        }

        ++temp;

        while (*temp != '\0')
        {
            pop(my_heap1);
            ++temp;
        }
        
        assert(isempty(my_heap1));
    }

    delete(my_heap1);
}