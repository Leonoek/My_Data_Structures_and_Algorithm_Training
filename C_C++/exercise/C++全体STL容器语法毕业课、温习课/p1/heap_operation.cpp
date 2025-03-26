// /* 给定一个数列，初始为空，请支持下面三种操作：
// 1.给定一个整数x，请将x加入到数列中。
// 2.输出数列中最小的数
// 3.删除数列中最小的数（如果有多个数最小，只删除1个）
// */

#include <iostream>
#include <queue>

int main(){
    std::priority_queue<int, std::vector<int>, std::greater<int>> my_pq;
    std::cout << "请输出操作的次数：\n";
    int n, op;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> op;
        if (op == 1)
        {
            std::cin >> op;
            my_pq.push(op);
        }else if (op == 2)
        {
            std::cout << my_pq.top() << std::endl;
        }else
        {
            my_pq.pop();
        }
    }
}
