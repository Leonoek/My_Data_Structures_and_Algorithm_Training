#include <iostream>

typedef struct BinaryTreeNode {
	int value;
	int height;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BinaryTreeNode;

BinaryTreeNode* InitBinaryTreeNode(int value) {
	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	node->value = value;
	node->height = 1;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

int Degree(BinaryTreeNode* root) {
	int left{};
	int right{};
	if (root->left == nullptr) left = 0;
	else left = root->left->height;
	if (root->right == nullptr) right = 0;
	else right = root->right->height;

	return left - right;
}

BinaryTreeNode* TurnLeft(BinaryTreeNode* root) {
	BinaryTreeNode* target = root->right;
	root->right = target->left;
	target->left = root;
	return target;
}

BinaryTreeNode* TurnRight(BinaryTreeNode* root) {
	BinaryTreeNode* target = root->left;
	root->left = target->right;
	target->right = root;
	return target;
}

BinaryTreeNode* Insert(BinaryTreeNode* root, int value) {
	if (root == nullptr)
	{
		return InitBinaryTreeNode(value);
	}
	
	if (value > root->value) {
		root->right = Insert(root->right, value);
		++(root->height);
	}
	else if (value < root->value) {
		root->left = Insert(root->left, value);
		++(root->height);
	}
	else {
		return root;
	}

	if (Degree(root) < -1) {
		if (Degree(root->right) < 0) {
			return TurnLeft(root);
		}
		else {
			root->right = TurnRight(root->right);
			return TurnLeft(root);
		}
	}
	else if (Degree(root) > 1) {
		if (Degree(root->left) < 0) {
			root->left = TurnLeft(root->left);
			return TurnRight(root);
		}
		else {
			return TurnRight(root);
		}
	}

	return root;
}

void Mid(BinaryTreeNode* root) {
	if (root == nullptr) {
		return;
	}

	while (root != nullptr) {
		Mid(root->left);
		printf("%d ", root->value);
		Mid(root->right);
		return;
	}
}

void Test1() {
	BinaryTreeNode* n1 = InitBinaryTreeNode(4);
	n1 = Insert(n1, 2);
	n1 = Insert(n1, 9);
	n1 = Insert(n1, 10);
	n1 = Insert(n1, 11);
	Mid(n1);
	printf("\n");

	n1 = Insert(n1, 10);
	Mid(n1);

	free(n1);
	n1 = nullptr;
}

void Test2() {
	BinaryTreeNode* n1 = InitBinaryTreeNode(5);
	n1 = Insert(n1, 3);
	n1 = Insert(n1, 2);

	Mid(n1);

	n1 = Insert(n1, 4);
	n1 = Insert(n1, 9);

	Mid(n1);

	free(n1);
	n1 = nullptr;
}

int main() {
	Test1();
	printf("\n");

	Test2();
}