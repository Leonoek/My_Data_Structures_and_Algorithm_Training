/*
将单向链表按某值划分成左边小，中间相等，右边大的形式
1.使用快速排序partition的方式
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define ARRAY_NUM 10
#define ARRAY_NUM_MAX_BOARD 100
typedef int Element_type;

struct linked_list {
    Element_type value;
    struct linked_list* next;
};

typedef struct linked_list* My_linked_list;

My_linked_list Create_node(Element_type val) {
    My_linked_list new_linked_list = (My_linked_list)malloc(sizeof(struct linked_list));
    new_linked_list ? 0 : fprintf(stderr, "no more heap memory!\n");
    new_linked_list->next = NULL;
    new_linked_list->value = val;
    return new_linked_list;
}

void swap(int* input_array, int a, int b){
    int tmp = input_array[a];
    input_array[a] = input_array[b];
    input_array[b] = tmp;
}

void partition(int* input_array, int left, int right){
    if (left == right)
    {
        return;
    }
    
    int i = left, j = right;
    while (i < j)
    {
        while (input_array[j] >= input_array[left] && i < j)
        {
            --j;
        }

        while (input_array[i] <= input_array[left] && i < j)
        {
            ++i;
        }
        
        swap(input_array, i, j);
    }
    swap(input_array, left,  i);
}


int main(){
    srand((unsigned int)time(NULL));
    int array_num = rand() % ARRAY_NUM;
    // int array_num = 2;
    if (!array_num)
    {
        array_num = rand() % ARRAY_NUM;
    }
    
    My_linked_list list_head = Create_node(-1);
    My_linked_list list_p = list_head;
    for (int i = 0; i < array_num; i++)
    {
        list_p->next = Create_node(rand() % ARRAY_NUM_MAX_BOARD);
        list_p = list_p->next;
    }
    My_linked_list list1 = list_head->next;

    int tmp_array[array_num] = {};
    for (int i = 0; i < array_num; i++)
    {
        tmp_array[i] = list1->value;
        list1 = list1->next;
    }
    
    partition(tmp_array, 0, array_num - 1);

    printf("\n");
    return 0;
}