/*
两个有环或者无环的链表，输出共同的节点，若没有则返回NULL
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define NODE_NUM_MAX 15
typedef int Element_type;

struct linked_list {
    struct linked_list* next;
};

typedef struct linked_list* My_linked_list;

My_linked_list Create_node(){
    My_linked_list new_linked_list = (My_linked_list)malloc(sizeof(struct linked_list));
    if (!new_linked_list)
    {
        fprintf(stderr, "no more heap memory!\n");
        exit(EXIT_FAILURE);
    }
    
    new_linked_list->next = NULL;
    return new_linked_list;
}

// 随机生成一个有环的链表
// num: 链表的长度，至少为3
// 返回值：链表的头指针，如果num小于3则返回NULL
// 生成的链表中，最后一个节点指向链表中的某一个节点，形成环。最后一个节点不会指向自己
My_linked_list Create_loop(int num){
    if (num  < 3)
    {
        return NULL;
    }
    
    srand(time(NULL));
    My_linked_list head = Create_node();
    My_linked_list cur = head;
    My_linked_list node_array[num];
    node_array[0] = head;
    for (int i = 0; i < num - 1; i++)
    {
        cur->next = Create_node();
        cur = cur->next;
        node_array[i + 1] = cur;
    }

    My_linked_list tmp;
    tmp = node_array[rand() % num];
    while (tmp == cur)
    {
        tmp = node_array[rand() % num];
    }

    cur->next = tmp;
    return head;
}

// 创建一条无环的链表并且不相交，无交点
My_linked_list Create_chain(int num){
    if (!num)
    {
        return NULL;
    }
    
    My_linked_list head = Create_node();
    My_linked_list cur = head;
    for (int i = 0; i < num; i++)
    {
        cur->next = Create_node();
        cur = cur->next;
    }
    return head;
}

// 创建两条无环的链表但是这两条链表相交，有1个交点
My_linked_list* Create_2links_intersect_noloop(int left_side_num, int right_side_num, int common_side_num){
    if (!common_side_num || !left_side_num || !left_side_num)
    {
        return NULL;
    }
    
    // 生成左边的链表
    My_linked_list left_head = Create_node();
    My_linked_list left_cur = left_head;
    for (int i = 0; i < left_side_num - 1; i++)
    {
        left_cur->next = Create_node();
        left_cur = left_cur->next;
    }
    
    // 生成右边的链表
    My_linked_list right_head = Create_node();
    My_linked_list right_cur = right_head;
    for (int j = 0; j < right_side_num - 1; j++)
    {
        right_cur->next = Create_node();
        right_cur = right_cur->next;
    }

    // 生成共同的链表
    My_linked_list common_head = Create_node();
    My_linked_list common_cur = common_head;
    for (int k = 0; k < common_side_num - 1; k++)
    {
        common_cur->next = Create_node();
        common_cur = common_cur->next;
    }

    left_cur->next = common_head;
    right_cur->next = common_head;

    My_linked_list* left_right_lists = malloc(sizeof(My_linked_list*) * 2);
    *left_right_lists = left_head;
    *(left_right_lists+1) = right_head;
    return  left_right_lists;
}

// 创建两条有环的链表并且这两条链表相交，有1个交点
My_linked_list* Create_2circles_1intersect_loop(int left_side_num, int right_side_num, int common_side_num){
    if (!common_side_num || !left_side_num || !left_side_num)
    {
        return NULL;
    }
    
    // 生成左边的链表
    My_linked_list left_head = Create_node();
    My_linked_list left_cur = left_head;
    for (int i = 0; i < left_side_num - 1; i++)
    {
        left_cur->next = Create_node();
        left_cur = left_cur->next;
    }
    
    // 生成右边的链表
    My_linked_list right_head = Create_node();
    My_linked_list right_cur = right_head;
    for (int j = 0; j < right_side_num - 1; j++)
    {
        right_cur->next = Create_node();
        right_cur = right_cur->next;
    }

    // 生成共同的链表
    My_linked_list common_head = Create_node();
    My_linked_list common_cur = common_head;
    for (int k = 0; k < common_side_num - 1; k++)
    {
        common_cur->next = Create_node();
        common_cur = common_cur->next;
    }

    left_cur->next = common_head;
    right_cur->next = common_head;
    common_cur->next = common_head;

    My_linked_list* left_right_lists = malloc(sizeof(My_linked_list*) * 2);
    *left_right_lists = left_head;
    *(left_right_lists+1) = right_head;
    return  left_right_lists;
}

// 创建两条有环的链表并且这两条链表相交，有2个交点
My_linked_list* Create_2circles_2intersect_loop(int left_side_num, int right_side_num, int common_side_num){
    if (!common_side_num || !left_side_num || !left_side_num)
    {
        return NULL;
    }
    
    // 生成左边的链表
    My_linked_list left_head = Create_node();
    My_linked_list left_cur = left_head;
    for (int i = 0; i < left_side_num - 1; i++)
    {
        left_cur->next = Create_node();
        left_cur = left_cur->next;
    }
    
    // 生成右边的链表
    My_linked_list right_head = Create_node();
    My_linked_list right_cur = right_head;
    for (int j = 0; j < right_side_num - 1; j++)
    {
        right_cur->next = Create_node();
        right_cur = right_cur->next;
    }

    // 生成共同的链表
    My_linked_list common_head = Create_node();
    My_linked_list common_cur = common_head;
    My_linked_list common_array[common_side_num];
    common_array[0] = common_head;
    for (int k = 0; k < common_side_num - 1; k++)
    {
        common_cur->next = Create_node();
        common_cur = common_cur->next;
        common_array[k + 1] = common_cur;
    }
    common_cur->next = common_head;

    left_cur->next = common_array[rand() % common_side_num];
    right_cur->next = common_array[rand() % common_side_num];
    while (left_cur->next == right_cur->next)
    {
        right_cur->next = common_array[rand() % common_side_num];
    }
    
    My_linked_list* left_right_lists = malloc(sizeof(My_linked_list*) * 2);
    *left_right_lists = left_head;
    *(left_right_lists+1) = right_head;
    return  left_right_lists;
}

// 使用快慢指针得到环节点的起始节点
// 如果有环则返回打结的节点，否则返回NULL
My_linked_list getloop_node(My_linked_list input_list){
    if (input_list == NULL || input_list->next == NULL || input_list->next->next == NULL)
    {
        return NULL;
    }
    
    My_linked_list lf = input_list->next->next;     // 快指针
    My_linked_list ls = input_list->next;     // 慢指针

    while (lf != ls)
    {
        if (lf->next == NULL || lf->next->next == NULL)
        {
            return NULL;
        }
        lf = lf->next->next;
        ls = ls->next;
    }
    
    lf = input_list;
    while (lf != ls)
    {
        lf = lf->next;
        ls = ls->next;
    }
    return lf;
}

// 输入两个没有环的链表，判断是否相交
My_linked_list get_common_node_noloop(My_linked_list input_list1, My_linked_list input_list2){
    if (input_list1 == NULL || input_list2 == NULL)
    {
        return NULL;
    }
    
    int list_node_num = 0;
    My_linked_list list1 = input_list1;
    while (list1->next)
    {
        list_node_num++;
        list1 = list1->next;
    }
    
    My_linked_list list2 = input_list2;
    while (list2->next)
    {
        list_node_num--;
        list2 = list2->next;
    }

    if (list1 != list2)
    {
        return NULL;
    }
    
    list1 = list_node_num > 0 ? input_list1 : input_list2;
    list2 = list1 == input_list1 ? input_list2 : input_list1;
    list_node_num = abs(list_node_num);

    while (list_node_num)
    {
        list1 = list1->next;
        list_node_num--;
    }
    
    while (list1 != NULL)
    {
        if (list1 == list2)
        {
            return list1;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return NULL;
}

// 输入两个有环的链表，判断是否相交
My_linked_list get_common_node_loop(My_linked_list input_list1, My_linked_list input_list2){
    if (input_list1 == NULL || input_list2 == NULL)
    {
        return NULL;
    }
    
    My_linked_list node1 = getloop_node(input_list1);
    My_linked_list node2 = getloop_node(input_list2);
    if (node1 == node2)
    {
        return node1;
    }else
    {
        My_linked_list tmp_node1 = node1->next;
        while (tmp_node1 != node1)
        {
            if (tmp_node1 == node2)
            {
                return node1;
            }
            tmp_node1 = tmp_node1->next;
        }
        
        return NULL;
    }
}

// 启动器
My_linked_list start(My_linked_list input_list1, My_linked_list input_list2){
    My_linked_list node1 = getloop_node(input_list1);
    My_linked_list node2 = getloop_node(input_list2);

    if (node1 && node2)
    {
        return get_common_node_loop(input_list1, input_list2);
    }else if (node1 == NULL && node2 == NULL)
    {
        return get_common_node_noloop(input_list1, input_list2);
    }else
    {
        return NULL;
    }
}

int main(){
    srand(time(NULL));
    int node_loop_num = rand() % NODE_NUM_MAX + 3;   // 满足形成有环链表的最低要求
    int node_chain_num = rand() % NODE_NUM_MAX;   // 无环链表

    /* ******************** noloop2noloop, without common node ******************** */
    /* ******************** 两个无环且没有共同点的节点 ******************** */
    My_linked_list list1 = Create_chain(node_loop_num);
    My_linked_list list2 = Create_chain(node_loop_num);
    My_linked_list result1_2 = start(list1, list2);
    
    /* ******************** noloop2noloop, have common node ******************** */
    /* ******************** 两个无环，有共同点的节点 ******************** */
    My_linked_list* left_right_lists1 = Create_2links_intersect_noloop(2, 1, 1);
    My_linked_list list3 = *left_right_lists1;
    My_linked_list list4 = *(left_right_lists1 + 1);
    My_linked_list result3_4 = start(list3, list4);

    /* ******************** noloop2noloop, have common node ******************** */
    /* ******************** 两个有环，没有共同点的节点 ******************** */
    My_linked_list list5 = Create_loop(node_loop_num);
    My_linked_list list6 = Create_loop(node_loop_num);
    My_linked_list result5_6 = start(list5, list6);

    /* ******************** noloop2noloop, have common node ******************** */
    /* ******************** 1个有环，1个无环，没有共同点的节点 ******************** */
    My_linked_list list7 = Create_loop(node_loop_num);
    My_linked_list list8 = Create_chain(node_chain_num);
    My_linked_list result7_8 = start(list7, list8);

    /* ******************** noloop2noloop, have common node ******************** */
    /* ******************** 两个有环，有1个共同点的节点 ******************** */
    My_linked_list* left_right_lists2 = Create_2circles_1intersect_loop(3, 5, 4);
    My_linked_list list9 = *left_right_lists2;
    My_linked_list list10 = *(left_right_lists2 + 1);
    My_linked_list result9_10 = start(list9, list10);

    /* ******************** noloop2noloop, have common node ******************** */
    /* ******************** 两个有环，有2个共同点的节点 ******************** */
    My_linked_list* left_right_lists3 = Create_2circles_2intersect_loop(3, 5, 4);
    My_linked_list list11 = *left_right_lists3;
    My_linked_list list12 = *(left_right_lists3 + 1);
    My_linked_list result11_12 = start(list11, list12);
    printf("\n");
    return 0;
}