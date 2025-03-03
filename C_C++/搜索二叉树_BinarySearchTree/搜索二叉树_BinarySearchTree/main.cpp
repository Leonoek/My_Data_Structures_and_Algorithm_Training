#include <iostream>

typedef struct BinaryTree {
	int val;
	BinaryTree* left;
	BinaryTree* right;
};



void Insert(BinaryTree** node, int val) {
	if (*node == nullptr) {
		BinaryTree* tempNode = (BinaryTree*)malloc(sizeof(BinaryTree));
		tempNode->val = val;
		tempNode->left = 0;
		tempNode->right = 0;
		*node = tempNode;
	}
	else {
		if (val > (*node)->val) {
			Insert(&((*node)->right), val);
		}
		else {
			Insert(&((*node)->left), val);
		}
	}
}

void MidPoint(BinaryTree** node) {
	if (*node == nullptr) return;
	else {
		MidPoint(&((*node)->left));
		printf("%d ", (*node)->val);
		MidPoint(&((*node)->right));
	}
}

int main() {
	BinaryTree* n1 = nullptr;
	int data;
	for (size_t i = 0; i < 8; i++)
	{
		std::cin >> data;
		Insert(&n1, data);
	}
	std::cout << std::endl;

	MidPoint(&n1);
	
}