/*
将单向链表按某值划分成左边小，中间相等，右边大的形式
2.使用6个变量记录指针，再串起来
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
    if (!new_linked_list)
    {
        fprintf(stderr, "no more heap memory!\n");
        exit(EXIT_FAILURE);
    }
    
    new_linked_list->next = NULL;
    new_linked_list->value = val;
    return new_linked_list;
}

void swap(int* input_array, int a, int b){
    int tmp = input_array[a];
    input_array[a] = input_array[b];
    input_array[b] = tmp;
}

// 像是串烧烤那样，把数组串起来
// 默认选择首个对象的值作为比较，小于的在前面，等于的在中间，小于的在后面
void Barbecue_skewers(My_linked_list* input_list){
    if (!(*input_list))
    {
        return;
    }
    
    My_linked_list h1 = NULL;
    My_linked_list h2 = NULL;
    My_linked_list m1 = NULL;
    My_linked_list m2 = NULL;
    My_linked_list e1 = NULL;
    My_linked_list e2 = NULL;

    My_linked_list p = *input_list;
    int target = p->value;
    while (p)
    {
        if (p->value < target)
        {
            if (!h1)
            {
                h1 = p;
                h2 = p;
            }else
            {
                h2->next = p;
                h2 = p;
            }
        }else if (p->value == target)
        {
            if (!m1)
            {
                m1 = p;
                m2 = p;
            }else
            {
                m2->next = p;
                m2 = p;
            }
        }else
        {
            if (!e1)
            {
                e1 = p;
                e2 = p;
            }else
            {
                e2->next = p;
                e2 = p;
            }
        }
        p = p->next;
    }

    // method 1
    /*
    if (h1)
    {
        if (m1)
        {
            h2->next = m1;
            if (e1)
            {
                m2->next = e1;
                e2->next = NULL;
            }else
            {
                m2->next = NULL;
            }
        }else
        {
            if (e1)
            {
                h2->next = e1;
                e2->next = NULL;
            }
        }
        *input_list = h1;
    }else if (m1)
    {
        if (e1)
        {
            m2->next = e1;
            e2->next = NULL;
        }
        *input_list = m1;
    }else
    {
        *input_list = e1;
    }
    */
    
    // method 2
    /*
    if (h1)
    {
        h2->next = m1;
    }
    
    if (e1)
    {
        m2->next = e1;
        e2->next = NULL;
    }
    
    *input_list = h1 ? (e1? h1 : (m2->next = NULL, h1)) : m1;
    */
    
    // method 3
    // if (h2 != NULL)
    // {
    //     h2->next = m1;
    //     m2 = m2 == NULL ? h2 : m2;
    // }
    
    // if (m2 != NULL)
    // {
    //     m2->next = e1;
    // }
    // *input_list =  h1 != NULL ? h1 : (m1 != NULL ? m1 : e1);
    
    //method 4
    if (h2 != NULL)
    {
        h2->next = m1;
        m2->next = e1;
    }

    if (e2)
    {
        e2->next = NULL;
    }
    
    *input_list =  h1 != NULL ? h1 : m1;
    
    printf("\n");
}

int main(){
    srand((unsigned int)time(NULL));
    int array_num = rand() % ARRAY_NUM;
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
    free(list_head);

    Barbecue_skewers(&list1);
    
    printf("\n");
    return 0;
}