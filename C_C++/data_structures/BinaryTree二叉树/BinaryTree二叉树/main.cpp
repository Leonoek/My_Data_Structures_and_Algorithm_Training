#include <iostream>

const int MAX_SIZE{ 10 };

typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* TreeInit(int var) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->val = var;
	node->right = nullptr;
	node->left = nullptr;
	return node;
}

// Ç°ÐòÅÅÐò£¬µÝ¹é
void PreOrder(TreeNode* node) {
	if (nullptr == node) {
		return;
	}

	printf("%d", node->val);

	PreOrder(node->left);
	PreOrder(node->right);
	
}

// ÖÐÐòÅÅÐò£¬µÝ¹é
void InOrder(TreeNode* node) {
	if (nullptr == node) {
		return;
	}
	InOrder(node->left);
	printf("%d", node->val);
	InOrder(node->right);

}

// ºóÐòÅÅÁÐ£¬µÝ¹é
void PostOrder(TreeNode* node) {
	if (nullptr == node) {
		return;
	}
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d", node->val);
}

// Ç°ÐòÅÅÐò£¬Õ»Ö¸Õë
void PreOrderByStack(TreeNode* node) {
	if (node == nullptr) printf("node is nullptr!");
	TreeNode* temp_array[MAX_SIZE]{};
	int sit = 0;

	while (node != nullptr || sit != 0) {
		while (node != nullptr) {
			printf("%d ", node->val);
			temp_array[sit++] = node;
			
			node = node->left;
			
		}

		if (sit != 0) {
			node = temp_array[--sit];
			node = node->right;
		}

	}
}

// ÖÐÐòÅÅÐò£¬Õ»Ö¸Õë
void InOrderByStack(TreeNode* node) {
	if (node == nullptr) printf("node is nullptr!");
	TreeNode* temp_array[MAX_SIZE]{};
	int sit = 0;

	while (node != nullptr || sit != 0) {
		while (node != nullptr) {
			temp_array[sit++] = node;
			node = node->left;
		}

		if (sit != 0) {
			node = temp_array[--sit];
			printf("%d ", node->val);
			node = node->right;
		}

	}
}

// ºóÐòÅÅÐò£¬Õ»Ö¸Õë
void PostOrderByStack(TreeNode* node) {
	if (node == nullptr) printf("node is nullptr!");
	TreeNode* temp_array[MAX_SIZE]{};
	int sit = -1;
	

	while (node != nullptr) {
		temp_array[++sit] = node;
		node = node->left;
	}

	TreeNode* temp_node = nullptr;

	while (sit != -1) {
		node = temp_array[sit--];

		if (node->right == nullptr || node->right == temp_node) {
			printf("%d ", node->val);
			temp_node = node;
		}
		else {
			temp_array[++sit] = node;
			node = node->right;
			while (node != nullptr) {
				temp_array[++sit] = node;
				node = node->left;
			}
		}
			
	}

}

void LevelOrderTraversal(TreeNode* node) {
	int sit = 0;
	int index = 0;
	TreeNode* tempArray[MAX_SIZE]{};
	TreeNode* tempNode = nullptr;
	tempArray[sit] = node;

	while (tempArray[index] != nullptr) {
		printf("%d", tempArray[index]->val);

		if (tempArray[index]->left != nullptr) {
			tempNode = tempArray[index]->left;
			tempArray[++sit] = tempNode;
		}

		if (tempArray[index]->right != nullptr) {
			tempNode = tempArray[index]->right;
			tempArray[++sit] = tempNode;
		}
		++index;
	}
}

// Ç°Ðò£¬Õ»ÅÅÐò
void UseCase1() {
	TreeNode* n1 = TreeInit(1);
	TreeNode* n2 = TreeInit(2);
	TreeNode* n3 = TreeInit(3);
	TreeNode* n4 = TreeInit(4);
	TreeNode* n5 = TreeInit(5);

	n1->left = n2;
	n2->left = n3;
	n2->right = n4;
	n1->right = n5;

	std::cout << "Ç°ÐòÅÅÐò£¬Õ»Ö¸ÕëÅÅÐò£º";
	PreOrderByStack(n1);
	std::cout << "" << std::endl;

	std::cout << "ÖÐÐòÅÅÐò£¬Õ»Ö¸ÕëÅÅÐò£º";
	InOrderByStack(n1);
	std::cout << "" << std::endl;

	std::cout << "ºóÐòÅÅÐò£¬Õ»Ö¸ÕëÅÅÐò£º";
	PostOrderByStack(n1);
	std::cout << "" << std::endl;

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

// ²åÈë
void UseCase2() {
	TreeNode* n1 = TreeInit(1);
	TreeNode* n2 = TreeInit(2);
	TreeNode* n3 = TreeInit(3);
	TreeNode* n4 = TreeInit(4);
	TreeNode* n5 = TreeInit(5);

	n1->left = n2;
	n2->left = n3;
	n2->right = n4;

	n2->left = n5;
	n5->left = n3;

	std::cout << "²åÈë£º ";
	PreOrder(n1);
	std::cout << std::endl;

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

// Ç°Ðò£¬ÖÐÐò£¬ºóÐò¡£µÝ¹é
void UseCase3() {
	TreeNode* n1 = TreeInit(1);
	TreeNode* n2 = TreeInit(2);
	TreeNode* n3 = TreeInit(3);
	TreeNode* n4 = TreeInit(4);
	TreeNode* n5 = TreeInit(5);

	n1->left = n2;
	n2->left = n3;
	n2->right = n4;
	n1->right = n5;

	// print
	std::cout << "Ç°Ðò£º ";
	PreOrder(n1);
	std::cout << std::endl;

	std::cout << "ÖÐÐò£º ";
	InOrder(n1);
	std::cout << std::endl;

	std::cout << "ºóÐò£º ";
	PostOrder(n1);
	std::cout << std::endl;
	

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

// Ç°Ðò£¬ÖÐÐò£¬ºóÐò¡£µÝ¹é
void UseCase4() {
	TreeNode* n1 = TreeInit(1);
	TreeNode* n2 = TreeInit(2);
	TreeNode* n3 = TreeInit(3);
	TreeNode* n4 = TreeInit(4);
	TreeNode* n5 = TreeInit(5);

	n1->left = n2;
	n2->left = n3;
	n2->right = n4;
	n1->right = n5;

	// print
	std::cout << "²ãÐò±éÀú£º ";
	LevelOrderTraversal(n1);
	std::cout << std::endl;

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

int main() {
	UseCase1();
	UseCase2();
	UseCase3();
	UseCase4();
	

	
}