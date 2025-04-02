/*
中位数
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
#include <cmath>

float median(const std::vector<int>& input_vector){
    std::priority_queue<int,std::vector<int>, std::greater<int>> less_queue;
    std::priority_queue<int,std::vector<int>, std::less<int>> greater_queue;
    greater_queue.push(input_vector[0]);

    for (auto i = input_vector.begin() + 1; i < input_vector.end(); ++i)
    {
        if (*i > greater_queue.top())
        {
            greater_queue.push(*i);
        }else
        {
            less_queue.push(*i);
        }
        
        int size = greater_queue.size() - less_queue.size();
        if (size > 1)
        {
            const auto greater = greater_queue.top();
            greater_queue.pop();
            less_queue.push(greater);
        }
        
        if (size < -1)
        {
            const auto less = less_queue.top();
            less_queue.pop();
            greater_queue.push(less);
        }
    }

    return (greater_queue.top() + less_queue.top()) / 2.0;
}

int main() {
    if (0 < -1)
    {
        std::cout << 111 << std::endl;
    }
    
    
    std::vector<int> vector1 {2, 1, 4, 2, 2, 5, 4, 1};
    
    auto result = median(vector1);
    std::cout << result << std::endl;
    return 0;
}