#include <stdlib.h>
#include <assert.h>
#include "array_queue.h"

struct queue
{
    Itemtype* array;
    int front;
    int size;
    int capacity;
};

Myqueue mycreate(int queue_size){
    assert(queue_size);
    Myqueue tmp_queue;
    Itemtype* tmp_array;

    tmp_queue = malloc(sizeof(struct queue));
    tmp_array = malloc(sizeof(Itemtype) * queue_size);
    tmp_queue->array = tmp_array;
    tmp_queue->capacity = queue_size;
    tmp_queue->front = 0;
    tmp_queue->size = 0;
    return tmp_queue;
}

void mypush(Myqueue myqueue, Itemtype target){
    assert(myqueue);
    myqueue->front = (myqueue->front - 1 + myqueue->capacity) % myqueue->capacity;
    myqueue->array[myqueue->front] = target;
    ++myqueue->size;
}

void myInject(Myqueue myqueue, Itemtype target){
    int rear;
    assert(myqueue);
    rear = (myqueue->front + myqueue->size) % myqueue->capacity;
    myqueue->array[rear] = target;
    ++myqueue->size;
}

Itemtype mypop(Myqueue myqueue){
    Itemtype tmp_item;
    assert(myqueue);
    tmp_item = myqueue->array[myqueue->front];
    --myqueue->size;
    myqueue->front = (myqueue->front + 1) % myqueue->capacity;
    return tmp_item;
}

Itemtype myeject(Myqueue myqueue){
    Itemtype tmp_item;
    assert(myqueue);
    tmp_item = myqueue->array[(myqueue->front + myqueue->size - 1) % myqueue->capacity];
    --myqueue->size;
    return tmp_item;
}

void mydelete(Myqueue myqueue){
    free(myqueue->array);
    free(myqueue);
}