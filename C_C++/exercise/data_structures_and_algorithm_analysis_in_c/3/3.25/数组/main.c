#include <stdio.h>
#include "array_queue.h"

int main(int argc, char *argv[])
{
    Myqueue myqueue;
    int target;

    myqueue = mycreate(10);
    mypush(myqueue, 1);
    mypush(myqueue, 2);
    mypush(myqueue, 3);
    target = mypop(myqueue);
    target = mypop(myqueue);
    target = mypop(myqueue);
    mydelete(myqueue);
    return 0;
}