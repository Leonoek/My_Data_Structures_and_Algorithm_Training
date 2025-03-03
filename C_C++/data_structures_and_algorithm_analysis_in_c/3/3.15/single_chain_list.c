#include <stdlib.h>
#include "single_chain_list.h"

struct SingleChainList
{
    int value;
    struct SingleChainList* next;
};

MyList create(int val){
    MyList mylist = malloc(sizeof(struct SingleChainList));
    if (mylist == NULL)
    {
        return NULL;
    }
    
    mylist->value = val;
    mylist->next = NULL;
    return mylist;
}

MyList add(MyList mylist, int val){
    while (mylist->next != NULL)
    {
        mylist = mylist->next;
    }

    MyList newlist = malloc(sizeof(struct SingleChainList));
    if (newlist == NULL)
    {
        return NULL;
    }

    newlist->next = NULL;
    newlist->value = val;
    mylist->next = newlist;
}

void delete(MyList mylist){
    MyList p = mylist->next;
    while (p != NULL)
    {
        free(mylist);
        mylist = p;
        p = p->next;
    }
    free(mylist);
}

MyList find_non_recursive(MyList mylist, int val){
    while (mylist != NULL && mylist->value != val)
    {
        mylist = mylist->next;
    }
    return mylist;
}

MyList find_recursive(MyList mylist, int val){
    if (mylist != NULL && mylist->value != val)
    {
        return find_recursive(mylist->next, val);
    }else{
        return mylist;
    }
}

MyList reverse(MyList mylist){
    int i;
    MyList temp = mylist;
    MyList *p = malloc(sizeof(MyList) * REVERSE_SIZE);
    if (p == NULL)
    {
        return NULL;
    }
    
    for (i = 0; temp != NULL; i++)
    {
        p[i] = temp;
        temp = temp->next;
    }
    
    mylist = p[--i];
    for (; i > -1; --i)
    {
        temp = p[i];
        if (i == 0)
        {
            temp->next = NULL;
            free(p);
            return mylist;
        }
        temp->next = p[i - 1];
    }
}

MyList find_previous(MyList mylist, int val){
    if (mylist == NULL)
    {
        return NULL;
    }

    if (mylist->value == val)
    {
        return NULL;
    }
    
    while (mylist != NULL && mylist->next->value != val)
    {
        mylist = mylist->next;
    }
    return mylist;
}

void self_adjusting(MyList* mylist, int val, MyList (*pfindfunc)(MyList mylist, int val)){
    MyList p, temp, pre;
    p = (*pfindfunc)(*mylist, val);
    pre = find_previous(*mylist, val);

    if (p == *mylist || p == NULL)
    {
        return;
    }else
    {
        temp = p->next;
        p->next = (*mylist);
        pre->next = temp;
        *mylist = p;
    }
}