#pragma once
// #ifndef AVL_H
// #define AVL_H

typedef int Itemtype;
typedef struct Binary_tree* Mytree;

Mytree mycreate(Itemtype val);

Itemtype get_value(Mytree mytree);

Mytree myadd(Mytree mytree, Itemtype val);

Mytree myremove(Mytree mytree, Itemtype val);

void myfree(Mytree mytree);

// #endif // !AVL_H