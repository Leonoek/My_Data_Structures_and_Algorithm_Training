#ifndef SINGLE_CHAIN_LIST_H
#define SINGLE_CHAIN_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (x > y ? y : x)

typedef struct Link_list* List;
typedef double item;

List create(int factor, int pow);

List add(List mylist, int factor, int pow);

void print(List mylist);

void delete(List mylist);

List multiply(List mylist1, List mylist2);

List mypow(List mylist, int pow);

#endif // !SINGLE_CHAIN_LIST_H