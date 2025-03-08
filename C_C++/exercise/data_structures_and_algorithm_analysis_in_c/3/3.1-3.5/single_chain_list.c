#include "single_chain_list.h"

struct Link_list
{
    int value;
    struct Link_list* next;
};


List create(int value){
    List my_list = malloc(sizeof(struct Link_list));
    if (my_list == NULL)
    {
        printf("fail to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    my_list->value = value;
    my_list->next = NULL;
}

void add(List mylist, int x){
    if (mylist == NULL)
    {
        printf("%s func input invalid\n", __func__);
    }
    
    if (mylist->next == NULL)
    {
        List temp_list = malloc(sizeof(struct Link_list));
        if (temp_list == NULL)
        {
            printf("fail to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        temp_list->value = x;
        temp_list->next = NULL;
        mylist->next = temp_list;
    }else
    {
        add(mylist->next, x);
    }
}

void print(List mylist){
    if (mylist == NULL)
    {
        printf("%s func input invalid\n", __func__);
    }

    do
    {
        printf("%3d", mylist->value);
    } while ((mylist->next != NULL ? mylist = mylist->next : 0));
    printf("\n");
}

void PrintLots(List list1, List list2){
    int i = 1;
    if (list1 == NULL && list2 == NULL)
    {
        printf("func: %s, input invalid", __func__);
    }
    
    do
    {
        for (; i <= list2->value; i++)
        {
            if (i == list2->value)
            {
                printf("num: %d, value: %d\n", i, list1->value);
            }
            list1 = list1->next;
        }
        
    } while ((list2->next != NULL ? list2 = list2->next : 0));
}

List swap_single_chain_list(List mylist, int num1, int num2){
    List temp_list1 ,temp_list2;
    temp_list1 = temp_list2 = NULL;
    if (num1 == 0 && num2 == 0)
    {
        printf("func: %s, input element num1 and num2 should bigger than 0", __func__);
    }

    if (abs(num1 - num2) > 1 && abs(num1 - num2) == 0)
    {
        printf("func: %s, input element num1 and num2 should no diff than 1", __func__);
    }
    
    for (int i = 1; i <= MIN(num1, num2); i++)
    {
        if (i == MIN(num1, num2))
        {
            if (temp_list1 == NULL)
            {
                temp_list1 = mylist;
                mylist = mylist->next;
                temp_list2 = mylist->next;

                temp_list1->next = temp_list2;
                mylist->next = temp_list1;
                return mylist;
            }
            
        }
        mylist = mylist->next;
    }

    return NULL;
}

void delete(List mylist){
    List temp_list = mylist->next;
    if (mylist == NULL)
    {
        printf("func: %s, invalid input", __func__);
    }

    do
    {
        free(mylist);

    }while ((temp_list != NULL ? (mylist = temp_list, temp_list = temp_list->next, mylist) : 0));
}

List intersection_single_link_list(List mylist1, List mylist2){
    List temp_list = malloc(sizeof(struct Link_list));
    temp_list->value = -1;
    List p = temp_list;

    List temp_list1, temp_list2;
    for (temp_list1 = mylist1; temp_list1 != NULL; temp_list1 = temp_list1->next)
    {
        for (temp_list2 = mylist2; temp_list2 != NULL; temp_list2 = temp_list2->next)
        {
            if (temp_list1->value == temp_list2->value)
            {
                if (p->value != -1)
                {
                    p->next = malloc(sizeof(struct Link_list));
                    p = p->next;
                }
                p->value = temp_list1->value;
                p->next = NULL;
            }
        }
    }
    
    if (temp_list->next == NULL)
    {
        free(temp_list);
        return NULL;
    }
    return temp_list;
}

List split_single_link_list(List mylist1, List mylist2){
    List p = mylist1;
    if (mylist1 == NULL && mylist2 == NULL)
    {
        printf("func: %s, error input\n", __func__);
    }
    
    while (p->next != NULL){
        p = p->next;
    }
    
    do
    {
        p->next = malloc(sizeof(struct Link_list));
        p->next->next = mylist2->next;
        p->next->value = mylist2->value;
        p = p->next;
        mylist2 = mylist2->next;
    } while (mylist2 != NULL);

    return mylist1;
}

List union_single_link_list(List mylist1, List mylist2){
    List temp_list = malloc(sizeof(struct Link_list));
    temp_list->value = -1;
    List p = temp_list;

    List temp_list1, temp_list2;
    for (temp_list1 = mylist1; temp_list1 != NULL; temp_list1 = temp_list1->next)
    {
        for (temp_list2 = mylist2; temp_list2 != NULL; temp_list2 = temp_list2->next)
        {
            if (temp_list1->value == temp_list2->value)
            {
                break;
            }

        }

        if (temp_list2 == NULL)
        {
            if (p->value != -1)
            {
                p->next = malloc(sizeof(struct Link_list));
                p = p->next;
            }
            p->value = temp_list1->value;
            p->next = NULL;
        }
        
    }
    
    if (temp_list->next == NULL)
    {
        free(temp_list);
        return NULL;
    }

    return split_single_link_list(temp_list, mylist2);
}