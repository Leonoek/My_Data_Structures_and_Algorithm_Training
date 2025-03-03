#ifndef DOUBLE_CHAIN_LIST_H
#define DOUBLE_CHAIN_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Double_Link_list* Double_Link;

Double_Link create_double_link(int value);

void add_double_link_next(Double_Link my_double_link, int x);

void print_double_link(Double_Link my_double_link);

void delete_double_link(Double_Link my_double_link);

Double_Link swap_double_chain_list(Double_Link my_double_link_list);

#endif // !DOUBLE_CHAIN_LIST_H