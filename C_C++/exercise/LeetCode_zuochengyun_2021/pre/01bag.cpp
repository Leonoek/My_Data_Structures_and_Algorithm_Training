/*
给定两个长度都为N的数组weights和values，weights[i]和values[i]分别代表
i号物品的重量和价值。给定一个正数bag，表示一个载重bag的袋子，你装的物
品不能超过这个重量。返回你能装下最多的价值是多少?
*/

#include <iostream>
#include <vector>
using namespace std;

int process(vector<int>& weight, vector<int>& value, int index, int alreadyWegiht, int MaxWeight){
    if (alreadyWegiht > MaxWeight)
    {
        return 0;
    }
    
    if (index == weight.size())
    {
        return 0;
    }
    
    return max(value[index] + process(weight, value, index + 1, alreadyWegiht + weight[index], MaxWeight),
        process(weight, value, index + 1, alreadyWegiht, MaxWeight));
}

int main(){
    vector<int> weight {1, 4, 2, 6, 1};
    vector<int> value {2, 4, 3, 2, 1};
    int result = process(weight, value, 0, 0, 10);
    cout << result << endl;
    return 0;
}