#include <iostream>
#include <map>
#include <set>

int main() {
    // map
    std::map<int, int> my_map;
    my_map.insert({1, 3});
    my_map[1] = 10;
    my_map[12] = 12;
    for (auto i : my_map)
    {
        std::cout << i.first << " : " << i.second << std::endl;
    }
    for (auto i = my_map.begin(); i != my_map.end(); i++)
    {
        std::cout << (*i).first << " : " << (*i).second << std::endl;
    }

    if (my_map.find(1) != my_map.end())
    {
        std::cout << "find 1\n";
    }

    // method 1
    // if (my_map.count(1))
    // {
    //     std::cout << "find 1\n";
    // }
    // method 2
    // my_map.count(1) ? (void)(std::cout << "find 1\n") : (void)0;
    // method 3
    my_map.count(1) ? std::cout << "find 1\n" : std::cout << "";

    auto t = my_map.lower_bound(1);
    if (t != my_map.end())
    {
        std::cout << "t: " << (*t).first << " : " << (*t).first << std::endl;
    }
    
    
    
    // set
    std::set<int> my_set;
    my_set.insert(1);
    my_set.insert(3);
    for (auto i : my_set)
    {
        std::cout << i << std::endl;
    }
    
    for (auto i = my_set.begin(); i != my_set.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return 0;
}