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

#include <vector>
#include <stdexcept>
#include <iostream>

class My_Priority_Queue {
private:
    std::unordered_map<std::shared_ptr<Node>, int> node_map;
    

    void heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].second < heap[parent].second) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapify_down(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:
    std::vector<std::pair<std::shared_ptr<Node>, int>> heap;
    My_Priority_Queue() = default;

    void push(std::pair<std::shared_ptr<Node>, int> node) {
        heap.push_back(node);
        node_map[node.first] = node.second;
        heapify_up(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) throw std::out_of_range("Queue is empty");
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    const std::shared_ptr<Node> top_node() const {
        if (heap.empty()) return nullptr;
        return heap[0].first;
    }

    const int top_distance() const {
        if (heap.empty()) throw std::out_of_range("Queue is empty");
        return heap[0].second;
    }

    bool find(const std::shared_ptr<Node>& input_node) {
        return node_map.find(input_node) != node_map.end();
    }

    int get(const std::shared_ptr<Node>& input_node) {
        return node_map.find(input_node)->second;
    }

    void set(const std::shared_ptr<Node>& input_node, int value) {
        node_map[input_node] = value;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i].first == input_node) {
                heap[i].second = value;
                heapify_up(i);
                break;
            }
        }
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

std::unordered_map<std::shared_ptr<Node>, int> Dijkstra(std::shared_ptr<Node> head){
    std::unordered_map<std::shared_ptr<Node>, int> distanceMap {{head, 0}};
    My_Priority_Queue selectedNodes;
    // selectedNodes.push({head, 0});
    std::shared_ptr<Node> miniNode = head;
    while (miniNode)
    {
        const int& distance = distanceMap[miniNode];
        for (const auto& edge : miniNode->edges)
        {
            const auto& toNode = edge->to;
            if (!selectedNodes.find(toNode))
            {
                selectedNodes.push({toNode, distance + edge->weight});
            }else if (selectedNodes.get(toNode) > distance + edge->weight)
            {
                selectedNodes.set(toNode, distance + edge->weight);
            }
        }
        
        if (!selectedNodes.empty()) {
            distanceMap.emplace(selectedNodes.top_node(), selectedNodes.top_distance());
            miniNode = selectedNodes.top_node();
            selectedNodes.pop();
        } else {
            miniNode = nullptr;
        }
    }
    return distanceMap;
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
    auto result = Dijkstra(graph->nodes.begin()->second);
    for (const auto& pair : result)
    {
        const auto& key = pair.first;
        const auto& value = pair.second;
        std::cout << key->value << " : " << value << std::endl;
    }
    
    return 0;
}