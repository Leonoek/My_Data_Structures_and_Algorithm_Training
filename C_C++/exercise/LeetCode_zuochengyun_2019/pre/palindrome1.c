/*
利用栈来判断是否是回文
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

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

// void Link_list_add_val(My_linked_list my_linked_list, Element_type val) {
//     if (my_linked_list == NULL)
//     {
//         return;
//     }

//     My_linked_list pre = NULL;
//     while (my_linked_list)
//     {
//         pre = my_linked_list;
//         my_linked_list = my_linked_list->next;
//     }

//     My_linked_list new_node = Create_node(val);
//     pre->next = new_node;
// }

// void Link_list_add_vals(My_linked_list my_linked_list, Element_type* input_array, int num) {
//     if (my_linked_list == NULL || input_array == NULL)
//     {
//         return;
//     }

//     My_linked_list pre = NULL;
//     while (my_linked_list)
//     {
//         pre = my_linked_list;
//         my_linked_list = my_linked_list->next;
//     }

//     My_linked_list new_node = NULL;
//     for (int i = 0; i < num; i++)
//     {
//         new_node = Create_node(input_array[i]);
//         pre->next = new_node;
//         pre = pre->next;
//     }
// }

My_linked_list Link_list_create_add_vals(Element_type* input_array, int num) {
    if (input_array == NULL)
    {
        return NULL;
    }

    My_linked_list new_node = NULL;
    My_linked_list p = NULL;
    for (int i = 0; i < num; i++)
    {
        if (!i)
        {
            new_node = Create_node(input_array[i]);
            p = new_node;
            continue;
        }
        
        p->next = Create_node(input_array[i]);
        p = p->next;
    }
    return new_node;
}

struct heap {
    Element_type* array;
    int sit;
    int size;
};

typedef struct heap* My_heap;

My_heap Create_heap(int size) {
    My_heap new_heap = (My_heap)malloc(sizeof(struct heap));
    new_heap ? 0 : fprintf(stderr, "no more heap memory!\n");
    new_heap->array = (Element_type*)malloc(sizeof(Element_type));
    new_heap->sit = -1;
    new_heap->size = size;
    return new_heap;
}

void Heap_add_val(My_heap my_heap, Element_type val) {
    if (my_heap == NULL)
    {
        return;
    }

    (my_heap->array)[++my_heap->sit] = val;
}

void Heap_add_vals(My_heap my_heap, Element_type* array, int num) {
    if (my_heap == NULL || array == NULL)
    {
        return;
    }

    for (int i = 0; i < num; i++)
    {
        (my_heap->array)[++my_heap->sit] = array[i];
    }
}

Element_type Heap_pop_val(My_heap my_heap) {
    if (my_heap == NULL)
    {
        return 0;
    }
    return (my_heap->array)[my_heap->sit--];
}

void Heap_print(My_heap my_heap){
    int tmp = my_heap->sit;
    printf("Heap: ");
    for (int i = tmp; i > -1; i--)
    {
        printf("%d ", (my_heap->array)[i]);
    }
    printf("\n");
}

// 全部压到栈的方式判断是不是回文
bool is_palindrome(My_linked_list my_list, My_heap my_heap, Element_type* input_array, int num){
    for (int i = 0; i < num / 2; i++)
    {
        if (Heap_pop_val(my_heap) != my_list->value)
        {
            return false;
        }
        my_list = my_list->next;
    }
    return true;
}

// 使用快慢指针，判断一端是否是回文
bool is_palindrome_fast_slow_pointer_heap(My_linked_list my_list, My_heap my_heap, Element_type* input_array, int num){
    // 慢指针
    My_linked_list link_ps = my_list;
    // 快指针
    My_linked_list link_pf = my_list;
    while (1)
    {
        if (link_pf == NULL || link_pf->next == NULL)
        {
            break;
        }else
        {
            link_ps = link_ps->next;
        }
        
        link_pf = link_pf->next->next;
    }
    
    link_ps = link_ps->next;
    while (link_ps)
    {
        Heap_add_val(my_heap, link_ps->value);
        link_ps = link_ps->next;
    }
    
    while (my_heap->sit != -1)
    {
        if (Heap_pop_val(my_heap) != my_list->value)
        {
            return false;
        }
        my_list = my_list->next;
    }
    return true;
}

int main(){
    // test
    /*
    My_linked_list link1 = Create_node(10);
    Link_list_add_val(link1, 5);
    Link_list_add_val(link1, 50);
    Link_list_add_val(link1, 21);

    My_heap heap1 = Create_heap(10);
    Heap_add_val(heap1, 2);
    Heap_add_val(heap1, 22);
    Heap_print(heap1);
    */

    // input
    int input1[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int input2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int input3[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    int input4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("\n********  normal heap  ********\n");
    My_linked_list link1 = Link_list_create_add_vals(input1, ARRAY_SIZE(input1));
    My_heap heap1 = Create_heap(10);
    Heap_add_vals(heap1, input1, ARRAY_SIZE(input1));
    int result = is_palindrome(link1, heap1, input1, ARRAY_SIZE(input1));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    My_linked_list link2 = Link_list_create_add_vals(input2, ARRAY_SIZE(input2));
    My_heap heap2 = Create_heap(10);
    Heap_add_vals(heap2, input2, ARRAY_SIZE(input2));
    result = is_palindrome(link2, heap2, input2, ARRAY_SIZE(input2));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    My_linked_list link3 = Link_list_create_add_vals(input3, ARRAY_SIZE(input3));
    My_heap heap3 = Create_heap(10);
    Heap_add_vals(heap3, input3, ARRAY_SIZE(input3));
    result = is_palindrome(link3, heap3, input3, ARRAY_SIZE(input3));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    My_linked_list link4 = Link_list_create_add_vals(input4, ARRAY_SIZE(input4));
    My_heap heap4 = Create_heap(10);
    Heap_add_vals(heap4, input4, ARRAY_SIZE(input4));
    result = is_palindrome(link4, heap4, input4, ARRAY_SIZE(input4));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    printf("\n********  fast slow pointer with heap ********\n");
    /* *************************************************************************** */
    My_linked_list link5 = Link_list_create_add_vals(input1, ARRAY_SIZE(input1));
    My_heap heap5 = Create_heap(10);
    result = is_palindrome_fast_slow_pointer_heap(link5, heap5, input1, ARRAY_SIZE(input1));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    My_linked_list link6 = Link_list_create_add_vals(input2, ARRAY_SIZE(input2));
    My_heap heap6 = Create_heap(10);
    result = is_palindrome_fast_slow_pointer_heap(link6, heap6, input2, ARRAY_SIZE(input2));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    My_linked_list link7 = Link_list_create_add_vals(input3, ARRAY_SIZE(input3));
    My_heap heap7 = Create_heap(10);
    result = is_palindrome_fast_slow_pointer_heap(link7, heap7, input3, ARRAY_SIZE(input3));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }

    /* *************************************************************************** */
    My_linked_list link8 = Link_list_create_add_vals(input4, ARRAY_SIZE(input4));
    My_heap heap8 = Create_heap(10);
    result = is_palindrome_fast_slow_pointer_heap(link8, heap8, input4, ARRAY_SIZE(input4));
    if (result)
    {
        printf("is palindrome\n");
    }else
    {
        printf("not palindrome\n");
    }
    printf("\n");
    return 0;
}