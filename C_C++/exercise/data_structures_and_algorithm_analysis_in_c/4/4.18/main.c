#include <stdio.h>
#include "AVL.h"


int main(int argc, char *argv[])
{
    int tmp_val;
    Mytree mytree = mycreate(40);

    mytree = myadd(mytree, 20);
    mytree = myadd(mytree, 60);
    mytree = myadd(mytree, 10);
    mytree = myadd(mytree, 30);

    mytree = myremove(mytree, 60);

    myfree(mytree);
    return 0;
}  