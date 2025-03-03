#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef int Itemtype;
typedef struct queue* Myqueue;

Myqueue mycreate(int queue_size);

void mypush(Myqueue myqueue, Itemtype target);

Itemtype mypop(Myqueue myqueue);

void mydelete(Myqueue myqueue);

#endif // !ARRAY_QUEUE_H