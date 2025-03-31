#include <iostream>
#include <string>
#include <cstring>

int main(){
    // 查找子集1
    std::string s {"welcome to chuanzhi cup chuanzhi"};
    auto pos = s.find("chuanzhi");
    int count = 0;
    while (pos != std::string::npos)
    {
        ++count;
        pos = s.find("chuanzhi", pos + sizeof("chuanzhi"));
    }
    
    std::cout << "count: " << count << std::endl;
    // 查找子集2
    std::string s2 {"welcome to chuanzhi cup chuanzhi"};
    int pos2 = 0, count2 = 0;
    do
    {
        pos = s.find("chuanzhi", pos + sizeof("chuanzhi"));
        if (pos != std::string::npos)
        {
            ++count2;
        }else
        {
            break;
        }
    } while (1);
    std::cout << "count2: " << count2 << std::endl;

    // 查找子集3
    std::string s3 {"welcome to chuanzhi cup chuanzhi"};
    int count3 = 0;
    for (int i = 0; i < s3.size(); i++)
    {
        if (s3.substr(i, strlen("chuanzhi")) == "chuanzhi")
        {
            count3++;
        }
        
    }
    std::cout << "count3: " << count3 << std::endl;
}
    