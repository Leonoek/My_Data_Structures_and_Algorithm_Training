#ifndef ORDINAL_SORTING_H
#define ORDINAL_SORTING_H

#include <stdbool.h>

typedef struct ordinal_num* Mynum;
typedef struct ordinal_head* Mysort;

Mysort mycreate();

void myempty(Mysort mysort);

void mydelete(Mysort mysort);

bool myadd(Mysort mysort, int val);

void myprint(Mysort mysort);

const int* sort(const int* array, int size, int digit, int buckets_num);

void test();

#endif // !ORDINAL_SORTING_H