#include "double_chain_list.h"

struct Double_Link_list
{
    int value;
    struct Double_Link_list* pre;
    struct Double_Link_list* next;
};

Double_Link create_double_link(int value){
    Double_Link my_double_link = malloc(sizeof(struct Double_Link_list));
    if (my_double_link == NULL)
    {
        printf("func: %s, fall to allocate memory", __func__);
    }

    my_double_link->value = value;
    my_double_link->next = NULL;
    my_double_link->pre = NULL;
    return my_double_link;
}

void add_double_link_next(Double_Link my_double_link, int x){
    Double_Link temp_double_link = malloc(sizeof(struct Double_Link_list));
    if (temp_double_link == NULL)
    {
        printf("func: %s, fall to allocate memory", __func__);
    }
    while (my_double_link->next != NULL)
    {
        my_double_link = my_double_link->next;
    }
    
    my_double_link->next = temp_double_link;
    temp_double_link->next = NULL;
    temp_double_link->pre = my_double_link;
    temp_double_link->value = x;
}

void print_double_link(Double_Link my_double_link){
    Double_Link temp_double_link;
    if (my_double_link == NULL)
    {
        printf("func: %s, error input", __func__);
    }

    while (my_double_link->pre != NULL)
    {
        my_double_link = my_double_link->pre;
    }
    
    temp_double_link = my_double_link->next;
    do
    {
        printf("%d\n", my_double_link->value);
    } while ((my_double_link->next == NULL ? 0 : (my_double_link = my_double_link->next)));
}

void delete_double_link(Double_Link my_double_link){
    Double_Link p = my_double_link->next;
    if (my_double_link == NULL)
    {
        printf("func: %s, fall to free memory\n");
    }
    
    do
    {
        free(my_double_link);
    } while ((p == NULL? 0 : (my_double_link = p, p = p->next, 1)));
}

Double_Link swap_double_chain_list(Double_Link my_double_link_list){
    if (my_double_link_list == NULL)
    {
        printf("func: %s, invalid input\n", __func__);
    }
    
    Double_Link pre_link, second_link, next_link;
    pre_link = my_double_link_list->pre;
    second_link = my_double_link_list->next;
    next_link = second_link->next;

    if (pre_link != NULL)
    {
        second_link->pre = pre_link;
        pre_link->next = second_link;
    }else
    {
        second_link->pre = NULL;
    }
    
    second_link->next = my_double_link_list;
    my_double_link_list->pre = second_link;

    if (next_link != NULL)
    {
        my_double_link_list->next = next_link;
        next_link->pre = my_double_link_list;
    }else
    {
        my_double_link_list->next = NULL;
    }
    
    return second_link;
}