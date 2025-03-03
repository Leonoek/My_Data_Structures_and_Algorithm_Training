#ifndef TEST_DOUBLE_LINK_LIST_H_
#define TEST_DOUBLE_LINK_LIST_H_

#include "double_chain_list.h"

void domain_double_link_list(){
    Double_Link my_double_link1 = create_double_link(50);
    add_double_link_next(my_double_link1, 60);
    add_double_link_next(my_double_link1, 70);
    print_double_link(my_double_link1);

    swap_double_chain_list(my_double_link1);
    print_double_link(my_double_link1);

    delete_double_link(my_double_link1);
}

#endif // !TEST_DOUBLE_LINK_LIST_H_