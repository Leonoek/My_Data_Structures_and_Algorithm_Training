#ifndef TEST_SINGLE_LINK_LIST_H
#define TEST_SINGLE_LINK_LIST_H

#include "single_chain_list.h"

void domain_single_chain_list(){
    List mylist1 = create(10);
    add(mylist1, 13);
    add(mylist1, 14);
    add(mylist1, 15);
    print(mylist1);

    List mylist2 = create(1);
    add(mylist2, 3);
    add(mylist2, 4);

    PrintLots(mylist1, mylist2);
    mylist1 = swap_single_chain_list(mylist1, 1, 2);
    if (mylist1 == NULL)
    {
        printf("func: %s, error swap_single_chain_list", __func__);
    }
    print(mylist1);

    delete(mylist1);
    delete(mylist2);
}


#endif // !TEST_SINGLE_LINK_LIST_H