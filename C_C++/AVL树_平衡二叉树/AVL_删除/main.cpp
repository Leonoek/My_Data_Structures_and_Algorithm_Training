#include <iostream>

typedef struct Node {
	int value;
	int height;
	Node* left;
	Node* right;
}Node;

Node* Init(int val) {
	Node* tempNode = (Node*)malloc(sizeof(Node));
	tempNode->value = val;
	tempNode->height = 1;
	tempNode->left = nullptr;
	tempNode->right = nullptr;
	return tempNode;
}

// 左旋
Node* LeftRotate(Node* root) {
	Node* tempNode = root->right;
	root->right = tempNode->left;
	tempNode->left = root;
	return tempNode;
}

// 右旋
Node* RightRotate(Node* root) {
	Node* tempNode = root->left;
	root->left = tempNode->right;
	tempNode->right = root;
	return tempNode;
}

// 度数
int Degree(Node* root) {
	int left{ 0 };
	int right{ 0 };

	if (root->left == nullptr) {
		left = 0;
	}
	else {
		left = root->left->height;
	}

	if (root->right == nullptr) {
		right = 0;
	}
	else {
		right = root->right->height;
	}

	return left - right;
}

int GetHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}

	return node->height;
}

int GetMax(int x, int y) {
	return (x > y) ? x : y;
}

// 插入
Node* Insert(Node* root, int val) {
	if (root == nullptr) {
		return Init(val);
	}

	if (val > root->value) {
		root->right = Insert(root->right, val);
	}
	else if (val < root->value) {
		root->left = Insert(root->left, val);
	}
	else {
		return root;
	}

	root->height = 1 + GetMax(GetHeight(root->left), GetHeight(root->right));

	if (Degree(root) < -1) {
		if (Degree(root->right) < 0) {
			// RR
			return LeftRotate(root);
		}
		else {
			// RL
			root->right = RightRotate(root->right);
			return LeftRotate(root);
		}
	}
	else if (Degree(root) > 1) {
		if (Degree(root->left) > 0) {
			// LL
			return RightRotate(root);
		}
		else {
			// LR
			root->left = LeftRotate(root->left);
			return RightRotate(root);
		}
	}
	else {
		return root;
	}
}

// 插入
Node* Delete(Node* root, int val) {
	if (root == nullptr) {
		return root;
	}

	if (val > root->value) {
		root->right = Delete(root->right, val);
	}
	else if (val < root->value) {
		root->left = Delete(root->left, val);
	}
	else {
		if (root->left == nullptr && root->right == nullptr) {
			free(root);
			root = nullptr;
		}
		else if (root->left == nullptr && root->right != nullptr) {
			Node* tempNode = root;
			root = root->right;
			free(root);
			root = nullptr;
		}
		else if (root->left != nullptr && root->right == nullptr) {
			Node* tempNode = root;
			root = root->left;
			free(root);
			root = nullptr;
		}
		else {
			Node* tempNode = root->right;
			while (tempNode->left != nullptr) {
				tempNode = tempNode->left;
			}
			tempNode->left = root->left;
			//tempNode->right = root->right->right;
			free(root);
			root = tempNode;
			tempNode = nullptr;
		}
	}

	if (root == nullptr) {
		return nullptr;
	}

	root->height = 1 + GetMax(GetHeight(root->left), GetHeight(root->right));

	if (Degree(root) < -1) {
		if (Degree(root->right) <= 0) {
			// RR
			return LeftRotate(root);
		}
		else {
			// RL
			root->right = RightRotate(root->right);
			return LeftRotate(root);
		}
	}
	else if (Degree(root) > 1) {
		if (Degree(root->left) >= 0) {
			// LL
			return RightRotate(root);
		}
		else {
			// LR
			root->left = LeftRotate(root->left);
			return RightRotate(root);
		}
	}
	else {
		return root;
	}

}

void Mid(Node* root) {
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

// 用例
Node* Usecase1() {
	Node* node = Insert(nullptr, 10);
	node = Insert(node, 4);
	node = Insert(node, 2);

	return node;
}

// 用例
Node* Usecase2() {
	Node* node = Insert(nullptr, 10);
	node = Insert(node, 11);
	node = Insert(node, 12);

	return node;
}

// 用例
Node* Usecase3() {
	Node* node = Insert(nullptr, 5);
	node = Insert(node, 3);
	node = Insert(node, 4);

	return node;
}

// 用例
Node* Usecase4() {
	Node* node = Insert(nullptr, 5);
	node = Insert(node, 7);
	node = Insert(node, 6);

	return node;
}

// 用例
Node* Usecase5() {
	Node* node = Insert(nullptr, 5);
	node = Insert(node, 3);
	node = Insert(node, 6);
	node = Insert(node, 2);
	node = Insert(node, 4);

	return node;
}

int main() {
	// insert
	Node* tempNode;
	tempNode = Usecase1();
	Mid(tempNode);
	std::cout << std::endl;
	tempNode = Usecase2();
	Mid(tempNode);
	std::cout << std::endl;
	tempNode = Usecase3();
	Mid(tempNode);
	std::cout << std::endl;
	tempNode = Usecase4();
	Mid(tempNode);
	std::cout << std::endl;

	// delete
	std::cout << std::endl;
	std::cout << "test delete..............." << std::endl;
	tempNode = Usecase5();
	Mid(tempNode);
	std::cout << "Then delete 5: ";
	tempNode = Delete(tempNode, 5);
	Mid(tempNode);

	std::cout << std::endl;
	std::cout << "Then delete 2: ";
	tempNode = Delete(tempNode, 2);
	Mid(tempNode);

	std::cout << std::endl;
	std::cout << "Then delete 3: ";
	tempNode = Delete(tempNode, 3);
	Mid(tempNode);

	return 0;
}