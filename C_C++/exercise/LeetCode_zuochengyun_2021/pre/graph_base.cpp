#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>

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


int main() {
    std::vector<std::vector<int>> input_vector {
        {5, 1, 2},
        {2, 1, 3},
        {4, 9, 6}
    };

    Graph graph = Graph();

    for (int i = 0; i < input_vector.size(); i++)
    {
        int weight = input_vector[i][0];
        int from = input_vector[i][1];
        int to = input_vector[i][2];

        if (graph.nodes.find(from) == graph.nodes.end())
        {
            graph.nodes.emplace(from, std::make_shared<Node>(from));
        }

        if (graph.nodes.find(to) == graph.nodes.end())
        {
            graph.nodes.emplace(to, std::make_shared<Node>(to));
        }
        
        std::shared_ptr<Node> fromNode = graph.nodes[from];
        std::shared_ptr<Node> toNode = graph.nodes[to];
        std::shared_ptr<Edge> new_Edge = std::make_shared<Edge>(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        ++fromNode->out;
        ++toNode->in;
        fromNode->edges.push_back(new_Edge);
        graph.edges.emplace(new_Edge);
    }

    return 0;
}