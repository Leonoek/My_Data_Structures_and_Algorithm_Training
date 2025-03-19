/*
折叠一个纸条，上面有7个折痕，请依次输出是凸还是凹
*/
#include <stdio.h>
#include <stdbool.h>
void process(int num, int target, bool down){
    if (num == target)
    {
        return;
    }
    
    process(num + 1, target, true);
    printf("%3d", down);
    process(num + 1, target, false);
}


int main(){
    process(0, 3, true);

    return 0;
}