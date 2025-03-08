#include <stdio.h>
#include "single_chain_list.h"
#include <malloc.h>
int main(int argc, char *argv[])
{
    MyList p;
    MyList mylist = create(10);
    add(mylist, 12);
    add(mylist, 82);
    
    p = find_previous(mylist, 10);
    p = find_previous(mylist, 12);
    p = find_previous(mylist, 82);

    p = find_non_recursive(mylist, 10);
    p = find_recursive(mylist, 82);

    self_adjusting(&mylist, 10, find_non_recursive);

    p = reverse(mylist);
    delete(mylist);

    return 0;
}