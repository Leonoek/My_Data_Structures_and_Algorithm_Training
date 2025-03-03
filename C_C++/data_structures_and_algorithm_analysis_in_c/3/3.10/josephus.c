#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

struct josephus
{
    int sit;
    struct josephus* next;
    struct josephus* pre;
};

Josephus create(int nums){
    int i;
    Josephus p, temp;
    Josephus my_josephus = malloc(sizeof(struct josephus));
    if (my_josephus == NULL)
    {
        printf("func: %s, error memory allocate\n", __func__);
        exit(EXIT_FAILURE);
    }
    
    for (i = 1, p = my_josephus; i <= nums; i++)
    {
        p->sit = i;
        if (i == nums)
        {
            p->next = my_josephus;
            my_josephus->pre = p;
            break;
        }
        
        temp = malloc(sizeof(struct josephus));
        if (temp == NULL)
        {
            printf("func: %s, error memory allocate\n", __func__);
            exit(EXIT_FAILURE);
        }
        p->next = temp;
        temp->pre = p;
        p = p->next;
    }
    return my_josephus;
}

void delete(Josephus my_josephus){
    Josephus p, temp;
    if (my_josephus == NULL)
    {
        printf("func: %s, error input\n", __func__);
        exit(EXIT_FAILURE);
    }
    
    p = my_josephus->next;
    while (p != my_josephus)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(my_josephus);
}

void game(Josephus my_josephus, int m, int n){
    int i;
    Josephus pre, next;
    if (my_josephus == NULL)
    {
        printf("func: %s, error input\n", __func__);
        exit(EXIT_FAILURE);
    }
    
    while (my_josephus->next != my_josephus)
    {
        for (i = 0; i < m; i++)
        {
            my_josephus = my_josephus->next;
        }
        
        pre = my_josephus->pre;
        next = my_josephus->next;

        if (next == pre)
        {
            printf("%d is out!\n", my_josephus->sit);
            printf("%d is win!\n", pre->sit);
            free(pre);
            free(my_josephus);
            return;
        }
        
        pre->next = next;
        next->pre = pre;
        printf("%d is out!\n", my_josephus->sit);
        free(my_josephus);
        my_josephus = next;
    }
}