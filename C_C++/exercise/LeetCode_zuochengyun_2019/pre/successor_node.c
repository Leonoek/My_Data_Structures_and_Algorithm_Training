/*
二叉树含有变量父母节点，求某一个节点的父节点
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Elementtype;

struct binary_tree{
    Elementtype value;
    struct binary_tree* left;
    struct binary_tree* right;
    struct binary_tree* parent;
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
    new_tree->parent = NULL;
    return new_tree;
}

Tree ADD_left(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->left = new_tree;
    new_tree->parent = input_array;
    return new_tree;
}

Tree ADD_right(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->right = new_tree;
    new_tree->parent = input_array;
    return new_tree;
}

Tree traverse_left_nodes(Tree root){
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Tree successor_node(Tree target){
    Tree node = target;
    if (node->right)
    {
        return traverse_left_nodes(node->right);
    }

    Tree parent = node->parent;
    while (!parent && node != parent->left)
    {
        node = parent;
        parent = node->parent;
    }
    
    return parent;
}

int main(){
    Tree t1 = Create(1);
    Tree t2 = ADD_left(t1, 2);
    Tree t3 = ADD_right(t1, 3);
    Tree t4 = ADD_left(t2, 4);
    Tree t5 = ADD_right(t2, 5);
    Tree t6 = ADD_left(t3, 6);
    Tree t7 = ADD_right(t3, 7);

    Tree t10 = Create(1);
    Tree t20 = ADD_left(t10, 2);
    Tree t30 = ADD_right(t10, 3);
    Tree t40 = ADD_left(t20, 4);
    Tree t50 = ADD_right(t20, 5);
    Tree t70 = ADD_right(t30, 7);

    Tree t100 = Create(1);
    Tree t200 = ADD_left(t100, 2);
    Tree t300 = ADD_right(t100, 3);
    Tree t400 = ADD_left(t200, 4);
    Tree t500 = ADD_right(t200, 5);
    Tree t600 = ADD_left(t300, 6);
    Tree t800 = ADD_left(t400, 8);

    Tree result = successor_node(t2);
    printf("\nt1: %d\n", result->value);

    result = successor_node(t40);
    printf("\nt10: %d\n", result->value);

    result = successor_node(t600);
    printf("\nt100: %d\n", result->value);

    return 0;
}