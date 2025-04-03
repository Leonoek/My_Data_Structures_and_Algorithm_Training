/*
39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为： [ [7], [2,2,3] ]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为： [ [2,2,2,2], [2,3,3], [3,5] ]
*/

#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> tmp;
void backtracking(vector<int> target_array, int target_sum, int sum, int index){
    if (sum == target_sum)
    {
        result.push_back(tmp);
        return;
    }
    
    for (int i = index; i < target_array.size() && sum + target_array[i] <= target_sum; i++)
    {
        tmp.push_back(target_array[i]);
        backtracking(target_array, target_sum, sum + target_array[i], i);
        tmp.pop_back();
    }
    
}

int main(){
    vector<int> candidates {2, 3, 6, 7};
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, 7, 0, 0);
    for (const auto& i : result)
    {
        for (const auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}
    