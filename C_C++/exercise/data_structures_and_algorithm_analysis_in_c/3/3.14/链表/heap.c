#include "heap.h"
#include <stdlib.h>

struct heap
{
    Item value;
    struct heap* next;
};

Myheap create(Item val){
    Myheap temp_heap = malloc(sizeof(struct heap));
    if (temp_heap == NULL)
    {
        return NULL;
    }
    
    temp_heap->value = val;
    temp_heap->next = NULL;
}

void add(Myheap* myheap, Item val){
    if (myheap == NULL)
    {
        return;
    }

    if (*myheap == NULL)
    {
        *myheap = create(val);
        return;
    }
    
    
    while ((*myheap)->next != NULL)
    {
        myheap = &(*myheap)->next;
    }
    
    (*myheap)->next = create(val);
}

void del(Myheap myheap){
    Myheap temp_heap;
    if (myheap == NULL)
    {
        return;
    }
    
    temp_heap = myheap->next;
    while (temp_heap != NULL)
    {
        free(myheap);
        myheap = temp_heap;
        temp_heap = temp_heap->next;
    }
    free(myheap);
}

Item pop(Myheap* myheap){
    Item temp;
    Myheap p = (*myheap)->next;
    if (myheap == NULL)
    {
        return -1;
    }

    temp = (*myheap)->value;
    free(*myheap);
    *myheap = p;
    return temp;
}