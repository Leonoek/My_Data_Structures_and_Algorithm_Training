#include <stdio.h>
#include "single_chain_list.h"

int main(int argc, char *argv[])
{
    MyList mylist = create(10);
    add(mylist, 12);
    add(mylist, 82);

    MyList p = find_non_recursive(mylist, 10);
    p = find_recursive(mylist, 82);

    p = reverse(mylist);

    delete(mylist);


    return 0;
}