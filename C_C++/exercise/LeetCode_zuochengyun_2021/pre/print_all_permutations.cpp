/*
打印所有的全排列
*/
#include <iostream>
#include <vector>
using namespace std;

void process(string& input_array, int i, vector<string>& output_array){
    if (i == input_array.size())
    {
        output_array.push_back(input_array);
        return;
    }
    bool visit[26] {0};
    for (int j = i; j < input_array.size(); j++)
    {
        if (!visit[input_array[j] - 'a'])
        {
            visit[input_array[j] - 'a'] = true;
            swap(input_array[i], input_array[j]);
            process(input_array, i + 1, output_array);
            swap(input_array[i], input_array[j]);
        }
    }
}

int main(){
    vector<string> my_strings;
    string input_array = "abca";
    process(input_array, 0, my_strings);
    for (const auto& my_string : my_strings)
    {
        cout << my_string << endl;
    }
    
    return 0;
}