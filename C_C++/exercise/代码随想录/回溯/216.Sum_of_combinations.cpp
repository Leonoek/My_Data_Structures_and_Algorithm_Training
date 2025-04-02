// /*
// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

// 说明：

// 所有数字都是正整数。
// 解集不能包含重复的组合。
// 示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]

// 示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]
// */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result_vector;
vector<int> dfs_vector;
void combination(int target_sum, int target_num, int tmp_sum, int index){
    if (tmp_sum > target_sum)
    {
        return;
    }
    
    if (tmp_sum == target_sum)
    {
        if (dfs_vector.size() == 3)
        {
            result_vector.push_back(dfs_vector);
        }
        return;
    }
    
    for (int i = index; i < target_sum - (target_num - dfs_vector.size()) + 1; i++)
    {
        dfs_vector.push_back(i);
        tmp_sum += i;
        combination(target_sum, target_num, tmp_sum, i + 1);
        tmp_sum -= i;
        dfs_vector.pop_back();
    }
    

    return;
}

int main(){
    int target_sum = 9;
    int target_num = 3;
    combination(target_sum, target_num, 0, 1);

    for (const auto& i : result_vector)
    {
        for (const auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}