/*
判断是否是完美二叉树/满二叉树
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// perfect binary tree,PBT,完美二叉树，满二叉树
struct tree_data{
    int depth;
    int nodes;    
};

struct tree_data* data_init(int depth, int nodes){
    struct tree_data* new_data = malloc(sizeof(struct tree_data));
    if (!new_data)
    {
        fprintf(stderr, "ERROR!no more memory");
        exit(EXIT_FAILURE);
    }
    new_data->depth = depth;
    new_data->nodes = nodes;
    return new_data;
}

struct tree_data* isPBT(Tree input_array){
    if (!input_array)
    {
        return data_init(0, 0);
    }
    struct tree_data* left_data = isPBT(input_array->left);
    struct tree_data* right_data = isPBT(input_array->right);
    int depth = (left_data->depth > right_data->depth ? left_data->depth : right_data->depth) + 1;
    int nodes = left_data->nodes + right_data->nodes + 1;
    // free(left_data);
    // free(right_data);
    return data_init(depth, nodes);
}

bool start(Tree input_array){
    if (!input_array)
    {
        return false;
    }
    int nodes = isPBT(input_array)->nodes;
    int depth = isPBT(input_array)->depth;
    return nodes == (1 << depth) - 1;
}



int main(){
    Tree t1 = Create(0);
    Tree t2 = ADD_left(t1, 1);
    Tree t3 = ADD_right(t1, 2);
    Tree t4 = ADD_left(t2, 3);
    Tree t5 = ADD_right(t2, 4);
    Tree t6 = ADD_left(t3, 5);
    Tree t7 = ADD_right(t3, 6);

    Tree t10 = Create(0);
    Tree t20 = ADD_left(t10, 1);
    Tree t30 = ADD_right(t10, 2);
    Tree t40 = ADD_left(t20, 3);
    Tree t50 = ADD_right(t20, 4);
    Tree t70 = ADD_right(t30, 6);

    Tree t100 = Create(0);
    Tree t200 = ADD_left(t100, 1);
    Tree t300 = ADD_right(t100, 2);
    Tree t400 = ADD_left(t200, 3);
    Tree t500 = ADD_right(t200, 4);
    Tree t600 = ADD_left(t300, 5);
    Tree t800 = ADD_left(t400, 6);

    int result = start(t1);
    printf("\nt1 isPBT: %d\n", result);

    result = start(t10);
    printf("\nt10 isPBT: %d\n", result);

    result = start(t100);
    printf("\nt100 isPBT: %d\n", result);
    return 0;
}