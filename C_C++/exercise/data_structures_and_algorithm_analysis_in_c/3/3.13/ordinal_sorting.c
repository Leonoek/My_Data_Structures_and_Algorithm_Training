#include "ordinal_sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ordinal_num
{
    int val;
    struct ordinal_num* next;
};

struct ordinal_head
{
    struct ordinal_num* head;
    struct ordinal_num* end;
};

Mysort mycreate(){
    Mysort mysort = malloc(sizeof(struct ordinal_head));
    if (mysort == NULL)
    {
        return NULL;
    }
    
    mysort->head = NULL;
    mysort->end = NULL;
    return mysort;
}

void myempty(Mysort mysort){
    Mynum p1, p2;
    if (mysort == NULL || mysort->head == NULL)
    {
        return;
    }
    
    p1 = mysort->head;
    if (p1 == NULL)
    {
        return;
    }
    
    p2 = p1->next;
    while (p2 != NULL)
    {
        free(p1);
        p1 = p2;
        p2 = p2->next;
    }
    free(p1);

    mysort->head = NULL;
    mysort->end = NULL;
}

void mydelete(Mysort mysort){
    myempty(mysort);
    free(mysort);
}

bool myadd(Mysort mysort, int val){
    Mynum p, tempsort;
    if (mysort == NULL)
    {
        return false;
    }
    
    tempsort = malloc(sizeof(struct ordinal_num));
    if (tempsort == NULL)
    {
        return false;
    }
    tempsort->val = val;
    tempsort->next = NULL;

    p = mysort->head;
    if (p == NULL)
    {
        p = tempsort;
        mysort->head = p;
        mysort->end = p;
        return true;
    }else{
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tempsort;
        mysort->end = p->next;
        return true;
    }
    
    
}

void myprint(Mysort mysort){
    Mynum p;
    if (mysort == NULL || mysort->head == NULL)
    {
        return;
    }
    
    p = mysort->head;
    while (p->next != NULL)
    {
        printf("%3d",p->val);
        p = p->next;
    }
    printf("%3d", p->val);
    printf("\n");
}

const int* sort(const int* array, int size, int digit, int buckets_num){
    int temp;
    int* result = malloc(sizeof(int) * size);
    int* temp_array = (int *)array;
    Mynum p;
    Mysort* bucket = malloc(sizeof(Mysort) * buckets_num);

    for (int t = 0; t < buckets_num; t++)
    {
        bucket[t] = mycreate();
    }
    
    for (int i = 0; digit > 0; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp = (temp_array[j] / (int)pow(buckets_num, i)) % buckets_num;
            myadd(bucket[temp], temp_array[j]);
        }
        
        for (int k = 0, b = 0; k < size;)
        {
            while (bucket[b]->head == NULL)
            {
                ++b;
            }
            p = bucket[b]->head;
            
            while (p != bucket[b]->end)
            {
                result[k++] = p->val;
                p = p->next;
            }
            result[k++] = p->val;

            ++b;
        }
        
        for (int q = 0; q < size; q++)
        {
            printf("%10d", result[q]);
        }
        
        printf("\n");

        temp_array = result;

        for (int s = 0; s < buckets_num; s++)
        {
            myempty(bucket[s]);
        }

        temp = buckets_num;
        while (temp > 1)
        {
            --digit;
            temp /= 10;
        }
        
    }
    
    return result;
}

void test(){
    Mysort mysort = mycreate();
    myadd(mysort, 10);
    myadd(mysort, 12);
    myadd(mysort, 9);
    myprint(mysort);
    mydelete(mysort);
}