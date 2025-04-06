#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int>& record, int i, int j){
    for (int k = 0; k < i; k++)
    {
        if (j == record[k] || abs(record[k] - j) == abs(i - k))
        {
            return false;
        }
        
    }
    return true;
}

int process(int i, vector<int>& record, int n){
    if (i == n)
    {
        return 1;
    }
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        if (isValid(record, i, j))
        {
            record[i] = j;
            res += process(i + 1, record, n);
        }
        
    }
    return res;
}

int start(int n){
    if(n < 1){
        return 0;
    }

    vector<int> record(n, 0);
    return process(0, record, n);
}





int main(){
    int result = start(8);
    cout << result << endl;
    return 0;
}
    