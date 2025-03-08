#include "single_chain_list.h"

struct Link_list
{
    item factor;
    item pow;
    struct Link_list* next;
};

List create(int factor, int pow){
    List my_list = malloc(sizeof(struct Link_list));
    if (my_list == NULL)
    {
        printf("fail to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    my_list->factor = factor;
    my_list->pow = pow;
    my_list->next = NULL;
}

List add(List mylist, int factor, int pow){
    List p, temp, pre = NULL;
    if (mylist == NULL)
    {
        return create(factor, pow);
    }
    
    for (p = mylist; p != NULL; pre = p, p = p->next)
    {
        if (pow > p->pow)
        {
            temp = malloc(sizeof(struct Link_list));
            temp->factor = factor;
            temp->pow = pow;
            temp->next = p;

            if (pre != NULL)
            {
                pre->next = temp;
                return mylist;
            }else
            {
                return temp;
            }
        }else if (pow == p->pow)
        {
            p->factor += factor;
            return mylist;
        }

    }

    temp = malloc(sizeof(struct Link_list));
    temp->factor = factor;
    temp->pow = pow;
    temp->next = NULL;
    pre->next = temp;
    return mylist;
}

void print(List mylist){
    if (mylist == NULL)
    {
        printf("%s func input invalid\n", __func__);
    }

    do
    {
        printf("%2.1lfx^%2.1lf\n", mylist->factor, mylist->pow);
    } while ((mylist->next != NULL ? mylist = mylist->next : 0));
    printf("\n");
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

List multiply(List mylist1, List mylist2){
    List temp_list1, temp_list2, temp = NULL;
    item factor, pow;

    for ( temp_list1 = mylist1; temp_list1 != NULL; temp_list1 = temp_list1->next)
    {
        for ( temp_list2 = mylist2; temp_list2 != NULL; temp_list2 = temp_list2->next)
        {
            factor = temp_list1->factor * temp_list2->factor;
            pow = temp_list1->pow + temp_list2->pow;
            temp = add(temp, factor, pow);
        }
    }
    return temp;
}

List mypow(List mylist, int pow){
    List temp = mylist;
    if (temp == NULL)
    {
        printf("func: %s, error input", __func__);
    }
    
    for (int i = 1; i < pow; i++)
    {
        temp = multiply(temp, temp);
    }
    
    return temp;
}