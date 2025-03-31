/*
使用贪心策略判断一个会议室最多能被使用几次
会议室从1点开始，假设有N场会议：
n1：1点开始，2点结束
n2：4点开始，5点结束
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

class Program
{
public:
    int start;
    int end;
    Program(const int& input_start, const int& input_end) : start{input_start}, end{input_end}{}
};

int bestArrange(const std::vector<Program>& programs, int timePoint){
    int result = 0;
    auto setCompare = [](const Program& program_a, const Program& program_b){
        return program_a.end > program_b.end;
    };
    std::priority_queue<Program, std::vector<Program>, decltype(setCompare)> myset(setCompare);
    for (int i = 0; i < programs.size(); i++)
    {
        myset.push(programs[i]);
    }
    
    for (int i = 0; i < programs.size(); i++)
    {
        const auto program = myset.top();
        myset.pop();
        if (program.start >= timePoint)
        {
            ++result;
            timePoint = program.end;
        }
    }

    return result;
}

int main() {
    std::vector<Program> programs{
        Program(1, 3),
        Program(1, 2),
        Program(5, 7),
        Program(4, 6),
        Program(2, 5),
    };

    auto result = bestArrange(programs, 1);
    std::cout << result << std::endl;

    return 0;
}