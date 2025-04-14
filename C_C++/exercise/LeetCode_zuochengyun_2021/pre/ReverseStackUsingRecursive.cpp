/*
给你一个栈，请你逆序这个栈，不能申请额外的数据结构，智能使用递归函数。如何实现？
*/

#include <iostream>
#include <stack>
using namespace std;

int f(stack<int>& input_stack){
    int result = input_stack.top();
    input_stack.pop();
    if (!input_stack.size())
    {
        return result;
    }else
    {
        int last = f(input_stack);
        input_stack.push(result);
        return last;
    }
}

void reverse(stack<int>& input_stack){
    if (!input_stack.size())
    {
        return;
    }
    
    int i = f(input_stack);
    reverse(input_stack);
    input_stack.push(i);
}

int main(){
    stack<int> input_stack;
    input_stack.push(1);
    input_stack.push(2);
    input_stack.push(3);
    reverse(input_stack);

    while (input_stack.size())
    {
        int val = input_stack.top();
        input_stack.pop();
        cout << val << endl;
    }
    
    
    return 0;
}