#include <iostream>
#include <vector>

using namespace std;

int process(int limit, int colomn, int left, int right){
    if (colomn == limit)
    {
        return 1;
    }
    int pos = limit &(~(colomn | left | right));
    int right_one;
    int res = 0;
    while (pos)
    {
        right_one = pos & (~pos + 1);
        pos = pos - right_one;
        res += process(limit,
                        colomn | right_one,
                        (left | right_one) << 1,
                        (right | right_one) >> 1);
    }
    return res;
}

int start(int n){
    if(n < 1 || n > 32){
        return 0;
    }

    int limit = n == 32 ? -1 : (1 << n) - 1;
    return process(limit, 0, 0, 0);
}


int main(){
    int result = start(8);
    cout << result << endl;
    return 0;
}
    