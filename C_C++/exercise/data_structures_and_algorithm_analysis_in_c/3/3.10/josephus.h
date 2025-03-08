#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

#include "josephus.h"

typedef struct josephus* Josephus;

Josephus create(int nums);

void delete(Josephus my_josephus);

void game(Josephus my_josephus, int m, int n);



#endif // !JOSEPHUS_H_