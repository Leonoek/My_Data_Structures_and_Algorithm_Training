#include <stdlib.h>
#include <assert.h>
#include "linked_binary_tree.h"

struct linked_list_binary_tree
{
    Itemtype value;
    struct linked_list_binary_tree* left_tree;
    struct linked_list_binary_tree* right_tree;
};

Mytree mycreate(Itemtype val){
    Mytree tmp_tree = malloc(sizeof(struct linked_list_binary_tree));
    tmp_tree->value = val;
    tmp_tree->left_tree = NULL;
    tmp_tree->right_tree = NULL;
    return tmp_tree;
}

void myadd(Mytree mytree, Itemtype val){
    Mytree tmp;
    assert(mytree);

    tmp = mycreate(val);
    while (1)
    {
        if (val > mytree->value)
        {
            if (mytree->right_tree == NULL)
            {
                mytree->right_tree = tmp;
                return;
            }else
            {
                mytree = mytree->right_tree;
            }
        }else if (val < mytree->value)
        {
            if (mytree->left_tree == NULL)
            {
                mytree->left_tree = tmp;
                return;
            }
            mytree = mytree->left_tree;
        }else
        {
            free(tmp);
            exit(EXIT_FAILURE);
        }
    }
}

bool myfind(Mytree mytree, Itemtype val){
    assert(mytree);
    while (1)
    {
        if (val > mytree->value)
        {
            if (mytree->right_tree == NULL)
            {
                return false;
            }
            mytree = mytree->right_tree;

        }else if (val < mytree->value)
        {
            if (mytree->left_tree == NULL)
            {
                return false;
            }
            
            mytree = mytree->left_tree;
        }else
        {
            return true;
        }
    }
}

// 二叉树删除
bool myremove_v1(Mytree* mytree, Itemtype val){
    Mytree pre, p, replace;
    assert(*mytree);    // 判断输入是否为NULL
    // 找到等待删除的节点
    pre = NULL, p = *mytree;
    while (p != NULL)
    {
        if (val > p->value)

        {
            if (p->right_tree == NULL)
            {
                return false;
            }
            pre = p;
            p = p->right_tree;

        }else if (val < p->value)
        {
            if (p->left_tree == NULL)
            {
                return false;
            }
            pre = p;
            p = p->left_tree;
        }else
        {
            break;
        }
    }
    
    // 对三种情况进行分析
    if (p->left_tree == NULL && p->right_tree == NULL)  // 叶子节点
    {
        if (pre != NULL)    // 删除的节点是根节点
        {
            if (p == pre->left_tree)
            {
                pre->left_tree = NULL;
            }else
            {
                pre->right_tree = NULL;
            }
        }
        free(p);
        *mytree = NULL;
    }else if (p->left_tree != NULL && p->right_tree == NULL) // 有左节点
    {
        if (pre == NULL)    // 删除根节点
        {
            *mytree = p->left_tree;
            free(p);
        }else
        {
            replace = p->left_tree;
            while (replace->right_tree != NULL)
            {
                replace = replace->right_tree;
            }

            if (p == pre->left_tree)
            {
                pre->left_tree = replace;
            }else if (p == pre->right_tree)
            {
                pre->right_tree = replace;
            }

            free(p);
        }
        
    }else if (p->left_tree == NULL && p->right_tree != NULL) // 有右节点
    {
        if (pre == NULL)    // 删除根节点
        {
            *mytree = p->right_tree;
            free(p);
        }else
        {
            replace = p->right_tree;
            while (replace->left_tree != NULL)
            {
                replace = replace->left_tree;
            }

            if (p == pre->left_tree)
            {
                pre->left_tree = replace;
            }else if (p == pre->right_tree)
            {
                pre->right_tree = replace;
            }

            free(p);
        }
    }else
    {
        if (pre == NULL)
        {
            *mytree = p->left_tree;
        }else if (pre->left_tree == p)
        {
            pre->left_tree = p->left_tree;
        }else
        {
            pre->right_tree = p->left_tree;
        }
        
        replace = p->left_tree;
        while (replace->right_tree != NULL)
        {
            replace = replace->right_tree;
        }
        
        replace->right_tree = p->right_tree;
        free(p);
    }
    return true;
}

Mytree myremove_v2(Mytree mytree, Itemtype val){
    Mytree tmp;
    if (mytree == NULL)
    {
        return NULL;
    }else if (val < mytree->value)
    {
        mytree->left_tree = myremove_v2(mytree->left_tree, val);
        return mytree;
    }else if (val > mytree->value)
    {
        mytree->right_tree = myremove_v2(mytree->right_tree, val);
        return mytree;
    }else
    {
        if (mytree->left_tree == NULL && mytree->right_tree == NULL)    // NO child
        {
            free(mytree);
            return NULL;
        }else if (mytree->left_tree != NULL && mytree->right_tree == NULL)  // have left child
        {
            tmp = mytree->left_tree;
            free(mytree);
            return tmp;
        }else if (mytree->left_tree == NULL && mytree->right_tree != NULL)  // have right child
        {
            tmp = mytree->right_tree;
            free(mytree);
            return tmp;
        }else
        {
            tmp = mytree->left_tree;
            while (tmp->right_tree != NULL)
            {
                tmp = tmp->right_tree;
            }
            tmp->right_tree = mytree->right_tree;
            tmp = mytree->left_tree;
            free(mytree);
            return tmp;
        }
    }
}

/* 递归的方式，用后序遍历删除节点 */
void mydelete(Mytree mytree){
    if (mytree == NULL)
    {
        return;
    }

    mydelete(mytree->left_tree);
    mydelete(mytree->right_tree);
    free(mytree);
}

void test(){
    Mytree mytree, p;
    bool result;
    mytree = mycreate(10);
    myadd(mytree, 20);
    
    
    myadd(mytree, 8);
    myadd(mytree, 9);
    myadd(mytree, 5);
    // myadd(mytree, 7);
    myadd(mytree, 30);
    myadd(mytree, 15);

    // result = myfind(mytree, 10);


    // result = myremove_v1(&mytree, 20);
    mytree = myremove_v2(mytree, 10);

    mydelete(mytree);
}