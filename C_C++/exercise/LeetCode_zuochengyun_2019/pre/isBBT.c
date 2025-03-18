/*
判断是否是平衡二叉树
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
/* method1 */
struct Balance
{
    bool isbalance;
    int height;
};

struct Balance* balance_data(bool isbalance, int height){
    struct Balance* new_balance = malloc(sizeof(struct Balance));
    if (!new_balance)
    {
        fprintf(stderr, "no more memory!");
        exit(EXIT_FAILURE);
    }
    
    new_balance->isbalance = isbalance;
    new_balance->height = height;
    return new_balance;
}

// balanced binary tree,bbt,平衡二叉树
struct Balance* isBBT(Tree input_array){
    if (!input_array)
    {
        return balance_data(true, 0);
    }
    
    struct Balance* left = isBBT(input_array->left);
    struct Balance* right = isBBT(input_array->right);

    int max_height = left->height > right->height ? left->height + 1 : right->height + 1;
    bool isheight_balance = abs(left->height - right->height) < 2 ? true : false;

    struct Balance* root = balance_data(isheight_balance, max_height);
    return root;
}

bool start(Tree input_array){
    return isBBT(input_array)->isbalance;
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

    Tree t1000 = Create(0);
    Tree t2000 = ADD_left(t1000, 1);
    Tree t3000 = ADD_right(t1000, 2);
    Tree t4000 = ADD_left(t2000, 3);
    Tree t8000 = ADD_left(t4000, 6);

    /* start1 */
    bool result = start(t1);
    printf("\nt1 isBBT: %d\n", result);

    result = start(t10);
    printf("\nt10 isBBT: %d\n", result);

    result = start(t100);
    printf("\nt100 isBBT: %d\n", result);

    result = start(t1000);
    printf("\nt1000 isBBT: %d\n", result);
    return 0;
}