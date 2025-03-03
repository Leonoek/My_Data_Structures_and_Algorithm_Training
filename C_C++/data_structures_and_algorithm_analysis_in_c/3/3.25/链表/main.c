#include <stdio.h>
#include "linkedlist_queue.h"

int main(int argc, char *argv[])
{
    int result;
    Myqueue myqueue = mycreate();
    myadd(myqueue, 10);
    myadd(myqueue, 9);
    myadd(myqueue, 1);

    result = mypop(myqueue);
    result = mypop(myqueue);
    result = mypop(myqueue);

    mydelete(myqueue);
    return 0;
}