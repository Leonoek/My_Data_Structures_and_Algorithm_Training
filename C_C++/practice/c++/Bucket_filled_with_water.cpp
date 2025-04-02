/*
贪心策略
盛水问题：选择两边高度最低的边 * 两边的长度 = 容积
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

// 输出下标
std::unique_ptr<std::vector<int>> Bucket_filled_with_water(const std::vector<int>& bucket){
    int front = 0;
    int end = bucket.size() - 1;

    int low = bucket[front] < bucket[end] ? bucket[front] : bucket[end];
    int record_volume = low * (end - front);
    int record_front = front;
    int record_end = end;
    for (int i = 0; i < bucket.size() && front < end; i++)
    {
        bucket[front] < bucket[end] ? ++front : --end;
        low = bucket[front] < bucket[end] ? bucket[front] : bucket[end];
        int volume = low * (end - front);
        if (volume > record_volume)
        {
            record_volume = volume;
            record_front = front;
            record_end = end;
        }
    }
    // return std::make_shared<std::vector<int>>(std::initializer_list<int>{record_front, record_end});
    return std::make_unique<std::vector<int>>(std::initializer_list<int>{record_front, record_end});
}

int main() {
    std::vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};
    const auto& ptr = Bucket_filled_with_water(height);
    std::cout << "sit is: " << (*ptr)[0] << " and " << (*ptr)[1] << std::endl;
    return 0;
}