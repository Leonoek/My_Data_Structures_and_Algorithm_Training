#ifndef SINGLE_CHAIN_LIST_H
#define SINGLE_CHAIN_LIST_H

#define REVERSE_SIZE 10

typedef struct SingleChainList* MyList;

MyList create(int val);

MyList add(MyList mylist, int val);

void delete(MyList mylist);

MyList find_non_recursive(MyList mylist, int val);

MyList find_recursive(MyList mylist, int val);

MyList reverse(MyList mylist);

#endif // !SINGLE_CHAIN_LIST_H
