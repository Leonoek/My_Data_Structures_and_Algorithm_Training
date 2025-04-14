/*
规定1和A对应、2和B对应、3和C对应.
那么一个数字字符串比如"111"，就可以转化为"AAA"、“KA"和"AK"
给定一个只有数字字符组成的字符串str，返回有多少种转化结果。
*/

#include <iostream>
#include <vector>
using namespace std;

int process(string& input_vector, int index){
    if (index == input_vector.size())
    {
        return 1;
    }
    
    if (input_vector[index] == '0')
    {
        return 0;
    }

    if (input_vector[index] == '1')
    {
        int result = process(input_vector, index + 1);
        if (index + 1 < input_vector.size())
        {
            result += process(input_vector, index + 2);
        }
        return result;
    }
    
    if (input_vector[index] == '2')
    {
        int result = process(input_vector, index + 1);
        if (index + 1 < input_vector.size() && (input_vector[index + 1] >= '0' && input_vector[index + 1] <= '6'))
        {
            result += process(input_vector, index + 2);
        }
        return result;
    }

    return process(input_vector, index + 1);
}

int main(){
    string array {"0"};
    int result = process(array, 0);
    cout << result << endl;
    return 0;
}