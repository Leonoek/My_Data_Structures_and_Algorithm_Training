/*
打印所有的子串
*/
#include <iostream>
#include <cstring>
using namespace std;

void process1(int i, string input_string){
    if (i < 0)
    {
        cout << input_string << endl;
    }else
    {
        process1(i - 1, input_string);
        input_string.erase(i, 1);
        process1(i - 1, input_string);
    }
}

void start1(string input_string){
    process1(input_string.size() - 1,input_string);
}

void process2(int i, char* input_string){
    if (i < 0)
    {
        cout << input_string << endl;
    }else
    {
        process2(i - 1, input_string);
        char tmp = input_string[i];
        input_string[i] = ' ';
        process2(i - 1, input_string);
        input_string[i] = tmp;
    }
}

void start2(char* input_string){
    process2(strlen(input_string) - 1, input_string);
}

int main(){
    start1("abc");
    char input_array[] = "abc";
    start2(input_array);
    return 0;
}