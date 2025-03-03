#ifndef SINGLE_CHAIN_LIST_H
#define SINGLE_CHAIN_LIST_H

typedef struct ChainList* MyChainList;
typedef struct Node* MyNode;

MyNode create(void);

void add(MyNode my_node, int val);

void delete(MyNode my_node, int val);

void test(void);

#endif // !SINGLE_CHAIN_LIST_H
