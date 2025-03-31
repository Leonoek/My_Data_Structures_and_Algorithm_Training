// /* 给定一个数列，初始为空，请支持下面三种操作：
// 1.给定一个整数x，请将x加入到数列中。
// 2.输出数列中最小的数
// 3.删除数列中最小的数（如果有多个数最小，只删除1个）
// */

#include <iostream>
#include <stack>

int main(){
// 出栈合法性
    int input_stack_array[] = {1, 2, 3, 4, 5};
    int array_num = 5;
    std::stack<int> s1;
    
    auto inspect_stack = [](std::stack<int>& input_stack, int* input_original_array, int* input_array, int input_num){
        for (int i = 0, j = 0; j < input_num; j = i)
        {
            do
            {
                input_stack.push(input_original_array[i++]);
            } while (input_stack.top() != input_array[j]);
            
            for (int tmp = i; input_stack.size() > 0; tmp--)
            {
                if (input_stack.top() != input_array[j + (i - tmp)])
                {
                    return false;
                }
                input_stack.pop();
            }
        }
        return true;
    };
    int stack_array1[] = {5, 4, 3, 2, 1};
    bool result = inspect_stack(s1, input_stack_array, stack_array1, array_num);
    std::stack<int>().swap(s1);
    std::cout << "result:" << result << std::endl;

    int stack_array2[] = {1, 2, 3, 4, 5};
    result = inspect_stack(s1, input_stack_array, stack_array2, array_num);
    std::stack<int>().swap(s1);
    std::cout << "result:" << result << std::endl;

    int stack_array3[] = {3, 1, 2, 4, 5};
    result = inspect_stack(s1, input_stack_array, stack_array3, array_num);
    std::stack<int>().swap(s1);
    std::cout << "result:" << result << std::endl;
    
    int stack_array4[] = {3, 2, 1, 4, 5};
    result = inspect_stack(s1, input_stack_array, stack_array4, array_num);
    std::stack<int>().swap(s1);
    std::cout << "result:" << result << std::endl;
}
