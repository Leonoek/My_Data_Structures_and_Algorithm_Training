/*
前缀树
一个字符串类型的数组arr1，另一个字符串类型的数组arr2。arr2中有哪些字符是arr1中出现的？请打印
arr2中有哪些字符是作为arr1中某个字符串前缀出现的？请打印
arr2中有哪些字符是作为arr1中某个字符串前缀出现的？请打印
arr2中出现次数最大的前缀
*/
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>

class TrieNode
{
public:
    int pass;
    int end;
    std::vector<std::shared_ptr<TrieNode>> nexts;
    TrieNode() :pass{0}, end{0}, nexts{26, nullptr}{};
    ~TrieNode(){};
};

class Trie
{
private:
    std::shared_ptr<TrieNode> root;
public:
    Trie() : root{std::make_shared<TrieNode>()}{};
    void insert(const std::string& input_string){
        if (input_string.empty())
        {
            return;
        }
        
        std::shared_ptr<TrieNode> node = root;
        ++node->pass;
        int index;
        for (int i = 0; i < input_string.length(); i++)
        {
            index = input_string[i] - 'a';
            if (node->nexts[index] == nullptr)
            {
                node->nexts[index] = std::make_shared<TrieNode>();
            }
            node = node->nexts[index];
            ++node->pass;
        }
        node->end++;
    }

    int search(const std::string& input_string){
        if (input_string.empty())
        {
            return 0;
        }

        std::shared_ptr<TrieNode> node = root;
        int index;
        for (int i = 0; i < input_string.length(); i++)
        {
            index = input_string[i] - 'a';
            if (node->nexts[index] == nullptr)
            {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }
    ~Trie(){};
};




int main() {
    Trie trie;
    std::string input1 {"hello world"};
    trie.insert(input1);

    std::string input2 {"hello"};
    int result = trie.search(input1);
    std::cout << result << std::endl;

    return 0;
}