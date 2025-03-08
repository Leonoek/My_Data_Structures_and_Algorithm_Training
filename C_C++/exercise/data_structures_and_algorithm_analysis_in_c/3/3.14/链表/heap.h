#ifndef HEAP_H
#define HEAP_H

typedef int Item;
typedef struct heap* Myheap;

Myheap create(Item val);

void add(Myheap* myheap, Item val);

void del(Myheap myheap);

Item pop(Myheap* myheap);



#endif // !HEAP