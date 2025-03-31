#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    // sort 排序
    std::vector<int> number1 {4, 8, 65, 25, 2, 99, 74, 7};
    
    // /* method1 */
    auto mycmp = [](int a, int b)->bool{return a < b;};
    std::sort(number1.begin(), number1.end(), mycmp);

    // /* method2 */
    // std::sort(number1.begin(), number1.end(), std::less<int>());

    // /* method3 */
    // std::sort(number1.begin(), number1.end());
    // std::reverse(number1.begin(), number1.end());

    auto vector_print = [](const std::vector<int>& target_vector){
        for (auto i : target_vector)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    };

    vector_print(number1);





    // find bigger element 找到更大的数
    auto iterator_print = [](std::vector<int>::iterator iterator, std::vector<int>::iterator end){
        std::cout << "element is: ";
        while (iterator != end)
        {
            std::cout << *iterator << " ";
            ++iterator;
        }
        std::cout << std::endl;
    };
    auto t = std::lower_bound(number1.begin(), number1.end(), 7);
    iterator_print(t, number1.end());

    // return site
    int sit = std::lower_bound(number1.begin(), number1.end(), 7) - number1.begin();
    std::cout << "sit is: " << sit << std::endl;

    auto number1_upper_bound = std::upper_bound(number1.begin(), number1.end(), 7);
    iterator_print(number1_upper_bound, number1.end());

    // return site
    int number1_upper_bound_site = std::upper_bound(number1.begin(), number1.end(), 7) - number1.begin();
    std::cout << "start sit is: " << number1_upper_bound_site << std::endl;







    // duplicate removal 去重
    std::vector<int> number2 {1, 8, 8, 45, 6, 99, 6, 1, 6, 75};
    std::sort(number2.begin(), number2.end(), std::less());
    auto number2_sit = std::unique(number2.begin(), number2.end());
    number2.erase(number2_sit, number2.end());
    vector_print(number2);




    std::vector<int> number3 {1, 8, 8, 45, 6, 99, 6, 1, 6, 75};
    int* x = &number3[5];
    auto test = std::find(number3.begin(), number3.end(), 45);
    if (test != number3.end())
    {
        std::cout << "find: " << *test << std::endl;
    }else
    {
        std::cout << "no find: " << std::endl;
    }
    
    
}