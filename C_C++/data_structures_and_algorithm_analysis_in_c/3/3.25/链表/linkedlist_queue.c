#include <stdlib.h>
#include <assert.h>
#include "linkedlist_queue.h"

struct node
{
    Itemtype value;
    struct node* next;
};

struct queue
{
    struct node* front; struct node* rear;
    int size;
};

Myqueue mycreate(void){
    Myqueue tmp_queue = malloc(sizeof(struct queue));
    assert(tmp_queue);
    tmp_queue->front = NULL;
    tmp_queue->rear = NULL;
    tmp_queue->size = 0;
}

void myadd(Myqueue myqueue, Itemtype val){
    Mynode tmp_node, p;
    assert(myqueue);

    tmp_node = malloc(sizeof(struct node));
    tmp_node->value = val;
    tmp_node->next = NULL;
    if (myqueue->front == NULL)
    {
        myqueue->front = tmp_node;
        myqueue->rear = myqueue->front;
    }else
    {
        p = myqueue->rear;
        p->next = tmp_node;
        myqueue->rear = p->next;
    }
    ++myqueue->size;
}

Itemtype mypop(Myqueue myqueue){
    Itemtype target;
    Mynode tmp_node;
    assert(myqueue && myqueue->size);
    tmp_node = myqueue->front->next;
    target = myqueue->front->value;
    free(myqueue->front);
    myqueue->front = tmp_node;
    --myqueue->size;
    return target;
}

void mydelete(Myqueue myqueue){
    Mynode p;
    assert(myqueue);
    while (myqueue->front != NULL)
    {
        p = myqueue->front->next;
        free(myqueue->front);
        myqueue->front = p;
    }
    free(myqueue);
}