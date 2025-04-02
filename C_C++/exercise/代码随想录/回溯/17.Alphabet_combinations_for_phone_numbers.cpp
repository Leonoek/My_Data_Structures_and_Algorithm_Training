/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
1
2   abc
3   def
4   ghi
5   jkl
6   mno
7   pqrs
8   tuv
9   wxyz
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明：尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const char* input_map[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
};

vector<string> result_vector;
string dfs_string;
void combination(const char*& input_array, int k, int n){
    if (dfs_string.size() == k)
    {
        result_vector.push_back(dfs_string);
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        int index = input_array[n] - '0';
        auto x = input_map[index][i];
        dfs_string.push_back(x);
        combination(input_array, k, n + 1);
        dfs_string.pop_back();
    }
}

// 版本二
class Solution {
private:
        const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
public:
    vector<string> result;
    void getCombinations(const string& digits, int index, const string& s) { // 注意参数的不同
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            getCombinations(digits, index + 1, s + letters[i]);  // 注意这里的不同
        }
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        getCombinations(digits, 0, "");
        // return result;
        return std::move(result);

    }
};

int main(){
    const char input_array[] = "233";
    const char* p = input_array;
    combination(p, strlen(input_array), 0);

    for (const auto& i : result_vector)
    {
        cout << i << endl;;
    }

    Solution s;
    const auto& s_result = s.letterCombinations("23");
    for (const auto& i : s_result)
    {
        cout << i << endl;;
    }
    
    return 0;
}