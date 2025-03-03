#ifndef SINGLE_CHAIN_LIST_H
#define SINGLE_CHAIN_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (x > y ? y : x)

typedef struct Link_list* List;

List create(int value);

void add(List mylist, int x);

void print(List mylist);

void PrintLots(List list1, List list2);

List swap_single_chain_list(List mylist, int num1, int num2);

void delete(List mylist);

List intersection_single_link_list(List mylist1, List mylist2);

List split_single_link_list(List mylist1, List mylist2);

List union_single_link_list(List mylist1, List mylist2);

#endif // !SINGLE_CHAIN_LIST_H