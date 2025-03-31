#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main() {
    std::unordered_map<int, int> my_um;
    std::unordered_set<int> my_us;

    my_um.insert({10, 20});
    my_um[5] = 10;
    my_us.insert(10);

    for (auto i : my_um)
    {
        std::cout << i.first << " : " << i.second << std::endl;
    }
    
    for (auto i = my_um.begin(); i != my_um.end(); i++)
    {
        std::cout << (*i).first << " : " << (*i).second << std::endl;
    }
    
    // /* **************************************** */
    for (auto i : my_us)
    {
        std::cout << i << std::endl;
    }
    
    for (auto i = my_us.begin(); i != my_us.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    bool result = my_um.count(10);
    result = my_us.count(10);

    return 0;
}