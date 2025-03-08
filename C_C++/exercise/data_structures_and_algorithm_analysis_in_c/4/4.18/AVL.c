#include "AVL.h"
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

struct Binary_tree
{
    Itemtype value;
    int height;
    struct Binary_tree* left;
    struct Binary_tree* right;
};

Mytree mycreate(Itemtype val){
    Mytree tmp = malloc(sizeof(struct Binary_tree));
    if (tmp == NULL)
    {
        return NULL;
    }
    memset(tmp, 0, sizeof(struct Binary_tree));
    tmp->value = val;
    tmp->height = 1;
    return tmp;
}

Itemtype get_value(Mytree mytree){
    return mytree->value;
}

static inline int max_height(Mytree mytree){
    if (mytree->left == NULL && mytree->right == NULL)
    {
        return 0;
    }else if (mytree->left == NULL && mytree->right != NULL)
    {
        return mytree->right->height;
    }else if (mytree->left != NULL && mytree->right == NULL)
    {
        return mytree->left->height;
    }else
    {
        return mytree->left->height > mytree->right->height ? mytree->left->height : mytree->right->height;
    }
}

static inline int mybalance(Mytree mytree){
    int left_height, right_height;
    if (mytree->left == NULL)
    {
        left_height = 0;
    }else
    {
        left_height = mytree->left->height;
    }
    if (mytree->right == NULL)
    {
        right_height = 0;
    }else
    {
        right_height = mytree->right->height;
    }
    return left_height - right_height;
}

static inline Mytree left_rotate(Mytree root_tree){
    Mytree next_tree = root_tree->right;
    root_tree->right = next_tree->left;
    next_tree->left = root_tree;
    return next_tree;
}

static inline Mytree right_rotate(Mytree root_tree){
    Mytree next_tree = root_tree->left;
    root_tree->left = next_tree->right;
    next_tree->right = root_tree;
    return next_tree;
}

Mytree myadd(Mytree mytree, Itemtype val){
    int balance;
    Mytree tmp;
    if (mytree == NULL)
    {
        return mycreate(val);
    }else if (val > mytree->value)
    {
        mytree->right = myadd(mytree->right, val);
    }else if (val < mytree->value)
    {
        mytree->left = myadd(mytree->left, val);
    }
    
    balance =  mybalance(mytree);   // 判断是否平衡

    if (balance > 1 || balance < -1)
    {
        if (balance > 1)    // 右旋
        {
            if (mybalance(mytree->left) > 0)    // LL
            {
                tmp = right_rotate(mytree);
            }else
            {
                mytree->left = left_rotate(mytree->left);
                tmp = right_rotate(mytree);
            }
        }else   // 左旋
        {
            if (mybalance(mytree->right) < 0)
            {
                tmp = left_rotate(mytree);
            }else
            {
                mytree->right = right_rotate(mytree->right);
                tmp = left_rotate(mytree);
            }
        }
        mytree->height = max_height(mytree) + 1;    // 更新高度
        return tmp;
    }

    mytree->height = max_height(mytree) + 1;    // 更新高度
    return mytree;
}

Mytree myremove(Mytree mytree, Itemtype val){
    int balance;
    Mytree tmp;
    if (mytree == NULL)
    {
        return NULL;
    }else if (val > mytree->value)
    {
        mytree->right = myremove(mytree->right, val);
    }else if (val < mytree->value)
    {
        mytree->left = myremove(mytree->left, val);
    }else
    {
        free(mytree);
        return NULL;
    }
    
    balance = mybalance(mytree);
    if (balance > 1 || balance < -1)
    {
        if (balance > 1)  // L
        {
            if (mybalance(mytree->left) > 0)    // L
            {
                tmp = right_rotate(mytree);
                tmp->right->height = max_height(tmp->right) + 1;
            }else   // R
            {
                mytree->left = left_rotate(mytree->left);
                mytree->left->left->height = max_height(mytree->left->left) + 1;
                tmp = right_rotate(mytree);
                tmp->right->height = max_height(tmp->right) + 1;
            }
        }else if (balance < -1)   // R
        {
            if (mybalance(mytree->right) > 0)    // L
            {
                mytree->right = right_rotate(mytree->right);
                mytree->right->right->height = max_height(mytree->right->right) + 1;
                tmp = left_rotate(mytree);
                tmp->left->height = max_height(tmp->left) + 1;
            }
            else    // R
            {
                tmp = left_rotate(mytree);
                tmp->left->height = max_height(tmp->left) + 1;
            }
            
        }
        tmp->height = max_height(tmp) + 1;
        return tmp;
    }
    mytree->height = max_height(mytree) + 1;
    return mytree;
}

void myfree(Mytree mytree){
    if (mytree == NULL)
    {
        return;
    }
    myfree(mytree->left);
    myfree(mytree->right);
    free(mytree);
}