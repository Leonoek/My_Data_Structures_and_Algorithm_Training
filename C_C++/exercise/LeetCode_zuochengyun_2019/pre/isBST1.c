/*
打印链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef int Elementtype;

struct binary_tree{
    Elementtype value;
    struct binary_tree* left;
    struct binary_tree* right;
};

typedef struct binary_tree* Tree;

Tree Create(Elementtype val){
    Tree new_tree = malloc(sizeof(struct binary_tree));
    if (!new_tree)
    {
        fprintf(stderr, "ERROR!no more memory");
        exit(EXIT_FAILURE);
    }
    new_tree->value = val;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

Tree ADD_left(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->left = new_tree;
    return new_tree;
}

Tree ADD_right(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->right = new_tree;
    return new_tree;
}

// 判断是否是二叉搜索树
int pre_val;
bool isBST(Tree input_array){
    if (input_array == NULL)
    {
        return true;
    }
    
    bool result = isBST(input_array->left);
    if (!result)
    {
        return false;
    }
    
    if (input_array->value < pre_val)
    {
        return false;
    }else
    {
        pre_val = input_array->value;
    }
    
    return isBST(input_array->right);
}

int main(){
    Tree t1 = Create(10);
    Tree t2 = ADD_left(t1, 5);
    Tree t3 = ADD_right(t1, 15);
    Tree t4 = ADD_left(t2, 4);
    Tree t5 = ADD_right(t2, 7);
    Tree t6 = ADD_left(t3, 12);
    Tree t7 = ADD_right(t3, 20);

    pre_val = INT_MIN;
    int result = isBST(t1);
    printf("%d\n", result);

    Tree t10 = Create(20);
    Tree t20 = ADD_left(t10, 10);
    Tree t30 = ADD_right(t10, 30);
    Tree t40 = ADD_left(t20, 5);
    Tree t50 = ADD_right(t20, 15);
    Tree t60 = ADD_left(t30, 5);
    Tree t70 = ADD_right(t30, 15);
    pre_val = INT_MIN;
    result = isBST(t10);
    printf("%d\n", result);
    return 0;
}