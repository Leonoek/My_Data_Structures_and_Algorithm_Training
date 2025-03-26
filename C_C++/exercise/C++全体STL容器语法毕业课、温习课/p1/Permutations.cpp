#include <iostream>
#include <algorithm>

int main(){
    // 全排列
    auto print_array = [](int* input_array, int input_num){
        for (int i = 0; i < input_num; i++)
        {
            std::cout << input_array[i] << " ";
        }
        std::cout << std::endl;
    };
    int a[] = {1, 2, 3};
    std::cout << "next_permutation: " << std::endl;
    do
    {
        print_array(a, 3);
    } while (std::next_permutation(a, a + 3));
    std::reverse(a, a + 3);
    std::cout << "prev_permutation: " << std::endl;
    do
    {
        print_array(a, 3);
    } while (std::prev_permutation(a, a + 3));
}
    