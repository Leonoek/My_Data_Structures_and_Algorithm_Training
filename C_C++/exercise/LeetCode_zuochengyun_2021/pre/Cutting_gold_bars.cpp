/*
贪心策略
使用哈夫曼树，计算两个子节点相加得到父节点的和
题目：一块金条切成两半，是需要花费和长度数值一样的铜板的。比如长度为20的金条，不管切成长度多大的两半，都需要花费20个铜板
*/
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>

int lessMoney(const std::vector<int>& input_vector){
    int sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    for (auto i : input_vector)
    {
        queue.push(i);
    }
    
    for (int j = 0; j < input_vector.size() - 1; j++)
    {
        auto x = queue.top();
        queue.pop();
        auto y = queue.top();
        queue.pop();
        x += y;
        sum += x;
        queue.push(x);
    }
    return sum;
}

int main() {
    // 总长为60的金块，需要切成10，20，30这三个长度的金条
    std::vector<int> my_vector {10, 20, 30};
    auto result = lessMoney(my_vector);
    std::cout << result << std::endl;
    return 0;
}