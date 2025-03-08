#include <iostream>

typedef struct ListNode {
    int var;
    ListNode* next;
}ListNode;

ListNode* NewListNode(int var) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->var = var;
    node->next = nullptr;
    return node;
}

ListNode* AccessNode(ListNode* node, int index) {
    for (size_t i = 0; i < index; ++i) {
        if (node->next == nullptr) return nullptr;
        node = node->next;
    }
    return node;
}

int Find(ListNode* node, int target) {
    int index{ 0 };
    while (node != nullptr) {
        if (node->var == target) return index;
        node = node->next;
        ++index;
    }
    return -1;
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
    if (temp_node == nullptr) printf("not found!\n");
    else printf("%d\n", temp_node->var);
    
    // find
    int temp = Find(n1, 3);
    if (temp == -1) printf("not found!\n");
    else printf("index is:%d", temp);
}
