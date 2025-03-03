#include <stdio.h>
#include "array_queue.h"

int main(int argc, char *argv[])
{
    Myqueue myqueue;
    int target;

    myqueue = mycreate(10);
    mypush(myqueue, 1);
    myInject(myqueue, 3);
    target = mypop(myqueue);
    target = myeject(myqueue);
    mydelete(myqueue);
    return 0;
}