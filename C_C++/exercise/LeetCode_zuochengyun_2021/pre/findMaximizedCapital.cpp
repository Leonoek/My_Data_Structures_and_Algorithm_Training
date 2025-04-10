/*
贪心策略
从项目中获得最大收益：k个项目，m数量的初始资金
每次做完项目就获得收益，支持你去做下一个项目。
输出最后获得的最大金钱
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

typedef struct Program
{
    int capital;
    int profits;
    Program(int input_capital, int input_profits) : capital{input_capital}, profits{input_profits}{}
}Program;

// 最大执行k次项目，初始资金w，项目收益profits，项目启动资金capital
int findMaximizedCapital(int k, int w, const std::vector<int>& profits, const std::vector<int>& capital){
    auto programCapitalCompare = [](const Program& A, const Program& B){
        return A.capital > B.capital;
    };
    std::priority_queue<Program, std::vector<Program>, decltype(programCapitalCompare)> capital_queue(programCapitalCompare);

    auto programProfitsCompare = [](const Program& A, const Program& B){
        return A.profits < B.profits;
    };
    std::priority_queue<Program, std::vector<Program>, decltype(programProfitsCompare)> profits_queue(programProfitsCompare);

    for (int i = 0; i < profits.size(); i++)
    {
        capital_queue.push(Program(capital[i], profits[i]));
    }
    
    for (int i = 0; i < k; i++)
    {
        while (w >= capital_queue.top().capital && !capital_queue.empty())
        {
            const auto program_capital = capital_queue.top();
            capital_queue.pop();
            profits_queue.push(program_capital);
        }
        
        if (profits_queue.empty())
        {
            return w;
        }
        w += profits_queue.top().profits;
        profits_queue.pop();
    }
    return w;
}


int main() {
    std::vector<int> capital {2, 1, 4, 2, 2};
    std::vector<int> profits {1, 3, 2, 4, 5};
    
    auto result = findMaximizedCapital(4, 2, profits, capital);
    std::cout << result << std::endl;
    return 0;
}