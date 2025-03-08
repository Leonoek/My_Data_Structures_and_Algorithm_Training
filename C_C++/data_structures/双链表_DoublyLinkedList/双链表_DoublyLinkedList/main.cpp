#include <iostream>

typedef struct DoublyLinkList {
	int var;
	DoublyLinkList* pre;
	DoublyLinkList* next;
} DoublyLinkList;

DoublyLinkList* DoublyLinkListInit(int value) {
	DoublyLinkList* node;
	node = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
	if (node == NULL) {
		return NULL;
	}
	node->var = value;
	node->pre = nullptr;
	node->next = nullptr;
	return node;
}

int main() {
	DoublyLinkList* node0 = DoublyLinkListInit(10);
	int value = node0->var;
	printf("%d\n", value);
	return 0;
}