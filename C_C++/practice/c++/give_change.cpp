/*
贪心策略
用最少的纸币找零钱
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

void give_change(const float& input_money){
    std::vector<float> moneys {100.0f, 50.0f, 20.0f, 10.0f, 5.0f, 1.0f, 0.5f, 0.1f, 0.01f};
    
    float sum = 0.f;
    float money = input_money;
    while (sum != input_money)
    {
        for (int i = 0; i < moneys.size(); i++)
        {
            if (moneys[i] <= money)
            {
                std::cout << moneys[i] << std::endl;
                sum += moneys[i];
                money -= moneys[i];
                break;
            }
        }
    }
}

int main() {
    // 换73块钱
    int money {73};
    give_change(money);
    return 0;
}