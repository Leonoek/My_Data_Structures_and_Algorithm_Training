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

class Edge;

class Node
{
public:
    int value;
    int in;
    int out;
    std::vector<std::shared_ptr<Node>> nexts;
    std::vector<std::shared_ptr<Edge>> edges;
    Node(int val) :value{val}, in{0}, out{0}{};
    ~Node(){};
};

class Edge
{
public:
    int weight;
    std::shared_ptr<Node> from;
    std::shared_ptr<Node> to;
    Edge(int weight, std::shared_ptr<Node> from, std::shared_ptr<Node> to) : weight{weight}, from{from}, to{to}{};
    ~Edge(){};
};

class Graph 
{
public:
    std::map<int, std::shared_ptr<Node>> nodes;
    std::set<std::shared_ptr<Edge>> edges;
    Graph(/* args */){};
    ~Graph(){};
};

std::shared_ptr<Graph> createGraph(const std::vector<std::vector<int>>& input_vector){
    std::shared_ptr<Graph> graph = std::make_shared<Graph>();
    for (int i = 0; i < input_vector.size(); i++)
    {
        int weight = input_vector[i][0];
        int from = input_vector[i][1];
        int to = input_vector[i][2];

        if (graph->nodes.find(from) == graph->nodes.end())
        {
            graph->nodes.emplace(from, std::make_shared<Node>(from));
        }

        if (graph->nodes.find(to) == graph->nodes.end())
        {
            graph->nodes.emplace(to, std::make_shared<Node>(to));
        }
        
        std::shared_ptr<Node> fromNode = graph->nodes[from];
        std::shared_ptr<Node> toNode = graph->nodes[to];
        std::shared_ptr<Edge> new_Edge = std::make_shared<Edge>(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        ++fromNode->out;
        ++toNode->in;
        fromNode->edges.push_back(new_Edge);
        graph->edges.emplace(new_Edge);
    }
    return graph;
}

std::list<std::shared_ptr<Node>> sortedTopology(const std::shared_ptr<Graph>& input_graph){
    if (!input_graph)
    {
        return {};
    }
    
    std::unordered_map<std::shared_ptr<Node>, int> all_nodes;
    std::queue<std::shared_ptr<Node>> zero_nodes;

    for (auto i : input_graph->nodes)
    {
        std::shared_ptr<Node> node = i.second;
        all_nodes.emplace(node, node->in);
        if (node->in == 0)
        {
            zero_nodes.push(node);
        }
    }
    
    std::list<std::shared_ptr<Node>> output_list;
    while (zero_nodes.size())
    {
        std::shared_ptr<Node> zeroNode = zero_nodes.front();
        zero_nodes.pop();
        output_list.push_back(zeroNode);
        for (auto i : zeroNode->nexts)
        {
            all_nodes[i] -= 1;
            all_nodes.emplace(i, all_nodes[i]);
            if (!all_nodes[i])
            {
                zero_nodes.push(i);
            }
        }
    }
    return output_list;
}

int main() {
    std::vector<std::vector<int>> vector1 {
        {5, 1, 2},
        {2, 1, 3},
        {2, 2, 4},
        {2, 2, 3},
        {4, 3, 4}
    };

    std::shared_ptr<Graph> graph = createGraph(vector1);
    std::list<std::shared_ptr<Node>> nodes = sortedTopology(graph);
    for (auto i : nodes)
    {
        std::cout << i->value << std::endl;
    }
    

    return 0;
}