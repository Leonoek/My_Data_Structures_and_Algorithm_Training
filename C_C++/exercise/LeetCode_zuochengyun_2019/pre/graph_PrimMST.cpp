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

std::set<std::shared_ptr<Edge>> PrimMST(const std::shared_ptr<Graph>& input_graph){
    auto EdgeCompare = [](const std::shared_ptr<Edge>& a, const std::shared_ptr<Edge>& b){
        return a->weight > b->weight;
    };
    std::priority_queue<std::shared_ptr<Edge>, std::vector<std::shared_ptr<Edge>>, decltype(EdgeCompare)> priorityQueue(EdgeCompare);
    std::set<std::shared_ptr<Node>> set;
    std::set<std::shared_ptr<Edge>> result;

    for (const auto& pair : input_graph->nodes)
    {
        const auto& node = pair.second;
        if (set.find(node) == set.end())
        {
            set.emplace(node);
            for (const auto& i : node->edges)
            {
                priorityQueue.push(i);
            }
            while (!priorityQueue.empty())
            {
                // method 1
                // const auto& edge = priorityQueue.top();
                const auto edge = priorityQueue.top();
                priorityQueue.pop();

                //method 2
                // auto edge = std::move(priorityQueue.top());
                // priorityQueue.pop();

                const auto& toNode = edge->to;
                if (set.find(toNode) == set.end())
                {
                    set.emplace(toNode);
                    result.emplace(edge);
                    for (const auto& i : toNode->edges)
                    {
                        priorityQueue.push(i);
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> vector1 {
        {7, 1, 2},
        // {7, 2, 1},
        {2, 1, 3},
        {4, 3, 4},
        {1000, 4, 2},
        {100, 1, 4},
        {100000, 2, 5}
    };

    std::shared_ptr<Graph> graph = createGraph(vector1);
    auto edges = PrimMST(graph);
    for (auto edge : edges)
    {
        std::cout << edge->weight << std::endl;
    }
    

    return 0;
}