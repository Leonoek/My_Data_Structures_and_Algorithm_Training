#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#define HEAP_ARRAY_SIZE 5

typedef char Itemtype;
typedef struct heap* Myheap;

Myheap create(void);

void add(Myheap* my_heap, Itemtype val);

void delete(Myheap my_heap);

bool isempty(Myheap my_heap);

bool isfull(Myheap my_heap);

Itemtype pop(Myheap my_heap);

Itemtype gettop(Myheap my_heap);

int getsize(Myheap my_heap);

void test();

#endif // !HEAP_H