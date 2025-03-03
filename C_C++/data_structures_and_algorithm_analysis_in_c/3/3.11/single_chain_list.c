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