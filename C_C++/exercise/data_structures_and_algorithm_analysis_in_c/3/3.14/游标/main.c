#include <stdio.h>
#include <math.h>
#include "Cursor.h"
#define SIZE(array) sizeof(array) / sizeof(array[0])

int main(int argc, char *argv[])
{
    // InitializeCursorSpaceSpace();
    // List mylist1 = Create(10);
    // Add(12, mylist1);
    // Add(122, mylist1);
    // Insert(20, Find(12, mylist1));
    // Delete(12, mylist1);
    // PrintCursor();

    int input[] = {1, 3, 2, 4, 1, 6, 1, 7};
    int array_size = SIZE(input);
    for (int i = 0; i < array_size; i++)
    {
        if (i % 2 == 0)
        {
            Add(input[i + 1], input[i + 1] + pow(10, input[i]));
        }
    }
    
    

    return 0;
}