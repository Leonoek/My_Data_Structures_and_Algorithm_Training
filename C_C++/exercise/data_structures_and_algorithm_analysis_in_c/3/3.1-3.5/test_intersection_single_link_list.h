#ifndef TEST_INTERSECTION_SINGLE_LINK_LIST_
#define TEST_INTERSECTION_SINGLE_LINK_LIST_

#include "single_chain_list.h"



void domain_intersection_single_link_list(){
    List mylist1 = create(10);
    add(mylist1, 13);
    add(mylist1, 14);
    add(mylist1, 15);
    print(mylist1);

    List mylist2 = create(1);
    add(mylist2, 13);
    add(mylist2, 15);

    List intersection_link_list = intersection_single_link_list(mylist1, mylist2);
    printf("intersection link list: ");
    print(intersection_link_list);

    delete(mylist1);
    delete(mylist2);
    delete(intersection_link_list);
}


#endif // !TEST_intersection_SINGLE_LINK_LIST_