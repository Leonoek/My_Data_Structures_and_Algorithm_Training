#include "single_chain_list.h"

int main(int argc, char *argv[])
{
    List list1 = create(2, 1);
    list1 = add(list1, 3, 0);
    print(list1);

    List list2 = create(1, 1);
    list2 = add(list2, 1, 0);
    print(list2);

    List list3 = multiply(list1, list2);
    print(list3);

    List list4 = mypow(list1, 3);
    print(list4);

    delete(list1);
    delete(list2);
    delete(list3);
    delete(list4);
    return 0;
}