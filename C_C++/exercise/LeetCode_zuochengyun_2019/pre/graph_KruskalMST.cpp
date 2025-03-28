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

class UnionFind
{
public:
    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<std::set<std::shared_ptr<Node>>>> hashNode;
    UnionFind(const std::shared_ptr<Graph>& input_graph){
        for (const auto& i : input_graph->nodes)
        {
            auto new_set = std::make_shared<std::set<std::shared_ptr<Node>>>(std::initializer_list<std::shared_ptr<Node>>{i.second});
            this->hashNode.emplace(i.second, new_set);
        }
    }

    bool isSameset(const std::shared_ptr<Node>& from, const std::shared_ptr<Node>& to){
        return hashNode[from] == hashNode[to];
    }

    void unionSet(const std::shared_ptr<Node>& from, const std::shared_ptr<Node>& to){
        const auto& to_nodes = hashNode[to];
        const auto& from_nodes = hashNode[from];
        // for (const auto& node : to_nodes)
        // {
        //     hashNode[from].emplace(node);
        // }
        // hashNode[to] = hashNode[from];

        for (const auto& node : *to_nodes) {
            from_nodes->emplace(node);
            // hashNode[node] = from_nodes;  // 更新 `hashNode`，使所有 `to` 集合中的节点指向 `from` 集合
        }
        hashNode[to] = hashNode[from];
    }
    ~UnionFind(){}
};

std::set<std::shared_ptr<Edge>> KruskalMST(const std::shared_ptr<Graph>& input_graph){
    UnionFind unionFind {input_graph};
    auto EdgeCompare = [](const std::shared_ptr<Edge>& a, const std::shared_ptr<Edge>& b){
        return a->weight > b->weight;
    };
    std::priority_queue<std::shared_ptr<Edge>, std::vector<std::shared_ptr<Edge>>, decltype(EdgeCompare)> priorityQueue(EdgeCompare);
    for (auto edge : input_graph->edges)
    {
        priorityQueue.push(edge);
    }
    std::set<std::shared_ptr<Edge>> result;
    while (priorityQueue.size())
    {
        auto edge = priorityQueue.top();
        priorityQueue.pop();
        if (!unionFind.isSameset(edge->from, edge->to))
        {
            result.emplace(edge);
            unionFind.unionSet(edge->from, edge->to);
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> vector1 {
        {7, 1, 2},
        {7, 2, 1},
        {2, 1, 3},
        {4, 3, 4},
        {1000, 4, 2},
        {100, 1, 4},
        {100000, 2, 5}
    };

    std::shared_ptr<Graph> graph = createGraph(vector1);
    auto edges = KruskalMST(graph);
    for (auto edge : edges)
    {
        std::cout << edge->weight << std::endl;
    }
    

    return 0;
}