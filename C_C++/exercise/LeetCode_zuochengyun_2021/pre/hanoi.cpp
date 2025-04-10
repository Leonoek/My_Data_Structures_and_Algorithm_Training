#include <iostream>
using namespace std;
void func(int i, string start, string end, string other){
    if (i == 1)
    {
        cout << " Move 1 from " << start << " to " << end << endl;
    }else
    {
        func(i - 1, start, other, end);
        cout << "Move " << start << " to " << end << endl;
        func(i - 1, other, end, start);
    }
}

void hanoi(int n){
    if (n > 0)
    {
        func(n, "左", "右", "中");
    }
    
}

int main(){
    hanoi(3);
    return 0;
}