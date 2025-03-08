#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "lazy_chain_list.h"

struct ChainList
{
    bool state;
    int value;
    struct ChainList* next;
};

struct Node
{
    int deleted;
    int undeleted;
    struct ChainList* next;
};

MyNode create(void){
    MyNode temp_node = malloc(sizeof(struct Node));
    temp_node->deleted = 0;
    temp_node->next = 0;
    temp_node->undeleted = 0;
    return temp_node;
}

void add(MyNode my_node, int val){
    MyChainList p, temp_chain_list;
    if (my_node == NULL)
    {
        return;
    }
    
    temp_chain_list = malloc(sizeof(struct ChainList));
    temp_chain_list->value = val;
    temp_chain_list->next = NULL;
    temp_chain_list->state = true;

    if (my_node->next == NULL)
    {
        my_node->next = temp_chain_list;
    }else
    {
        p = my_node->next;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp_chain_list;
    }

    my_node->undeleted++;
}

/* 寻找前一个元素 */
static MyChainList find_previous(MyNode my_node, MyChainList my_chain_list){
    MyChainList p;
    if (my_node->next == my_chain_list) // 当前算法只会有一种情况
    {
        return NULL;
    }
    
    p = my_node->next;
    while (p != NULL)
    {
        if (p->next == my_chain_list)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/* 遍历删除 */
static void traverse_and_delete(MyNode my_node){
    MyChainList p, temp;
    // if (my_node == NULL)
    // {
    //     return;
    // }
    
    p = my_node->next;
    while (p != NULL)
    {
        if (p->state == false)
        {
            temp = find_previous(my_node, p);
            if (temp != NULL)
            {
                temp->next = p->next;
            }else{
                my_node->next = p->next;
            }
            temp = p;
            p = p->next;
            free(temp);
            continue;
        }
        p = p->next;
    }
}

void delete(MyNode my_node, int val){
    MyChainList p;

    if (my_node == NULL)
    {
        return;
    }
    
    if (my_node->next == NULL)
    {
        return;
    }
    
    p = my_node->next;
    while (p != NULL)
    {
        if (p->value == val && p->state == true)
        {
            break;
        }
        p = p->next;
    }

    if (p == NULL)
    {
        return;
    }else{
        p->state = false;
    }
    
    my_node->undeleted--;
    my_node->deleted++;

    if (my_node->undeleted == my_node->deleted)
    {
        traverse_and_delete(my_node);
    }
}

void test(void){
    MyChainList mychain;
    MyNode mynode1 = create();
    add(mynode1, 10);
    add(mynode1, 20);
    add(mynode1, 30);
    add(mynode1, 40);

    delete(mynode1, 10);
    delete(mynode1, 40);

    mychain = find_previous(mynode1, mynode1->next->next);
    return;
}