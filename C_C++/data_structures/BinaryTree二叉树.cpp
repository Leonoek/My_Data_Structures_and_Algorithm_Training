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

// ǰ�����򣬵ݹ�
void PreOrder(TreeNode* node) {
	if (nullptr == node) {
		return;
	}

	printf("%d", node->val);

	PreOrder(node->left);
	PreOrder(node->right);
	
}

// �������򣬵ݹ�
void InOrder(TreeNode* node) {
	if (nullptr == node) {
		return;
	}
	InOrder(node->left);
	printf("%d", node->val);
	InOrder(node->right);

}

// �������У��ݹ�
void PostOrder(TreeNode* node) {
	if (nullptr == node) {
		return;
	}
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d", node->val);
}

// ǰ������ջָ��
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

// ��������ջָ��
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

// ��������ջָ��
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

// ǰ��ջ����
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

	std::cout << "ǰ������ջָ������";
	PreOrderByStack(n1);
	std::cout << "" << std::endl;

	std::cout << "��������ջָ������";
	InOrderByStack(n1);
	std::cout << "" << std::endl;

	std::cout << "��������ջָ������";
	PostOrderByStack(n1);
	std::cout << "" << std::endl;

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

// ����
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

	std::cout << "���룺 ";
	PreOrder(n1);
	std::cout << std::endl;

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

// ǰ�����򣬺��򡣵ݹ�
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
	std::cout << "ǰ�� ";
	PreOrder(n1);
	std::cout << std::endl;

	std::cout << "���� ";
	InOrder(n1);
	std::cout << std::endl;

	std::cout << "���� ";
	PostOrder(n1);
	std::cout << std::endl;
	

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

// ǰ�����򣬺��򡣵ݹ�
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
	std::cout << "��������� ";
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