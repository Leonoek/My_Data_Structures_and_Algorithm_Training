/*
反转链表
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int var;
    struct ListNode* next;
}ListNode;

ListNode* NewListNode(int var) {
    ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
    node->var = var;
    node->next = NULL;
    return node;
}

ListNode* AccessNode(ListNode* node, int index) {
    for (size_t i = 0; i < index; ++i) {
        if (node->next == NULL) return NULL;
        node = node->next;
    }
    return node;
}

int Find(ListNode* node, int target) {
    int index = 0;
    while (node != NULL) {
        if (node->var == target) return index;
        node = node->next;
        ++index;
    }
    return -1;
}

void Filp(ListNode** node){
    if ((*node)->next == NULL || *node == NULL)
    {
        return;
    }
    
    ListNode* p1 = *node;
    ListNode* p2 = p1->next;
    p1->next = NULL;
    ListNode* tmp = NULL;
    while (p2)
    {
        tmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;
    }
    *node = p1;
}

int main() {
    ListNode* n1 = NewListNode(1);
    ListNode* n2 = NewListNode(2);
    ListNode* n3 = NewListNode(3);

    n1->next = n2;
    n2->next = n3;

    // insert
    ListNode* n4 = NewListNode(4);
    n1->next = n4;
    n4->next = n3;

    //// delete
    n1->next = n2;
    free(n4);

    // find index of node's var
    ListNode* temp_node = AccessNode(n1, 2);
    if (temp_node == NULL) printf("not found!\n");
    else printf("%d\n", temp_node->var);
    
    // find
    int temp = Find(n1, 3);
    if (temp == -1) printf("not found!\n");
    else printf("index is:%d", temp);

    Filp(&n1);
    printf("filp!\n");
}
