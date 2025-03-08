#ifndef TEST_UNION_SINGLE_LINK_LIST_
#define TEST_UNION_SINGLE_LINK_LIST_

#include "single_chain_list.h"

void domain_union_single_link_list(){
    List mylist1 = create(10);
    add(mylist1, 13);
    add(mylist1, 14);
    add(mylist1, 15);
    print(mylist1);

    List mylist2 = create(1);
    add(mylist2, 13);
    add(mylist2, 15);
    print(mylist2);

    List union_link_list = union_single_link_list(mylist1, mylist2);
    printf("union link list: ");
    print(union_link_list);

    delete(mylist1);
    delete(mylist2);
    delete(union_link_list);
}

#endif // !TEST_intersection_SINGLE_LINK_LIST_