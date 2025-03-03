#include <stdio.h>
#include "josephus.h"

int main(int argc, char *argv[])
{
    Josephus my_josephus = create(5);
    game(my_josephus, 1, 5);


    return 0;
}