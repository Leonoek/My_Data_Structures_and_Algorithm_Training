#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

typedef int Itemtype;
typedef struct node* Mynode;
typedef struct queue* Myqueue;

Myqueue mycreate(void);

void myadd(Myqueue myqueue, Itemtype val);

Itemtype mypop(Myqueue myqueue);

void mydelete(Myqueue myqueue);

#endif // !LINKEDLIST_QUEUE_H