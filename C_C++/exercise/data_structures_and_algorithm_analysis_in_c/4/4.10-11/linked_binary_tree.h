#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <stdbool.h>

typedef int Itemtype;
typedef struct linked_list_binary_tree* Mytree;

Mytree mycreate(Itemtype val);

void myadd(Mytree mytree, Itemtype val);

bool myfind(Mytree mytree, Itemtype val);

bool myremove_v1(Mytree* mytree, Itemtype val);

Mytree myremove_v2(Mytree mytree, Itemtype val);

void mydelete(Mytree mytree);

void test();

#endif // !LINKED_BINARY_TREE_H