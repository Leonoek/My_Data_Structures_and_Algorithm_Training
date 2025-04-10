/*
有序单链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Add_node(My_linked_list* my_linked_list, Element_type val) {
    if (*my_linked_list == NULL)
    {
        return;
    }

    My_linked_list p = *my_linked_list;
    My_linked_list pre = NULL;
    My_linked_list new_node = NULL;
    while (p)
    {
        if (p->value >= val)
        {
            new_node = Create_node(val);
            new_node ? 0 : fprintf(stderr, "no more heap memory!\n");

            if (pre)
            {
                pre->next = new_node;
                new_node->next = p;
                return;
            }
            else
            {
                new_node->next = p;
                *my_linked_list = new_node;
                return;
            }
        }
        pre = p;
        p = p->next;
    }

    new_node = Create_node(val);
    pre->next = new_node;
}

Element_type* Common_value(My_linked_list l1, My_linked_list l2) {
    if (l1 == NULL || l2 == NULL)
    {
        return NULL;
    }

    Element_type* element_list = malloc(sizeof(Element_type) * 100);
    memset(element_list, -1, sizeof(Element_type) * 100);
    int element_site = 0;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->value > l2->value)
        {
            l2 = l2->next;
        }
        else if (l1->value < l2->value)
        {
            l1 = l1->next;
        }
        else
        {
            element_list[element_site++] = l1->value;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return element_list;
}

int main() {
    My_linked_list my_list1 = Create_node(2);
    Add_node(&my_list1, 0);
    Add_node(&my_list1, 1);
    Add_node(&my_list1, 5);
    Add_node(&my_list1, 3);
    Add_node(&my_list1, 8);
    printf("\n");

    My_linked_list my_list2 = Create_node(2);
    Add_node(&my_list2, 10);
    Add_node(&my_list2, 1);
    Add_node(&my_list2, 5);
    Add_node(&my_list2, 3);
    Add_node(&my_list2, 4);

    printf("common: \n");
    Element_type* p = Common_value(my_list1, my_list2);
    while (*p != -1)
    {
        printf("%4d", *p++);
    }

    return 0;
}