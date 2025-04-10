/*
图
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* linked_list */
typedef int Element_type;

struct linked_nexts_list {
    struct Node* next_node;
    struct linked_nexts_list* next;
};

struct linked_nexts_list* Create_linked_nexts_list(struct Node* input_node){
    struct linked_nexts_list* new_linked_list = (struct linked_nexts_list*)malloc(sizeof(struct linked_nexts_list));
    if (!new_linked_list)
    {
        fprintf(stderr, "no more heap memory!\n");
        exit(EXIT_FAILURE);
    }
    
    new_linked_list->next_node = input_node;
    new_linked_list->next = NULL;
    return new_linked_list;
}

void Add_linked_nexts_list(struct linked_nexts_list** input_linked_list, struct Node* input_node){
    // struct linked_nexts_list* p = *input_linked_list;
    // if (!p)
    // {
    //     p = Create_linked_nexts_list(input_node);
    //     return;
    // }


    if (!*input_linked_list)
    {
        *input_linked_list = Create_linked_nexts_list(input_node);
        return;
    }
    
    struct linked_nexts_list* p = *input_linked_list;
    while (p->next)
    {
        p = p->next;
    }
    p->next = Create_linked_nexts_list(input_node);
}

/* linked_edges_list */
struct linked_edges_list {
    struct Edges* next_edge;
    struct linked_edges_list* next;
};

struct linked_edges_list* Create_linked_edges_list(struct Edges* input_edge){
    struct linked_edges_list* new_linked_edges_list = (struct linked_edges_list*)malloc(sizeof(struct linked_edges_list));
    if (!new_linked_edges_list)
    {
        fprintf(stderr, "no more heap memory!\n");
        exit(EXIT_FAILURE);
    }
    
    new_linked_edges_list->next_edge = input_edge;
    new_linked_edges_list->next = NULL;
    return new_linked_edges_list;
}

void Add_linked_edges_list(struct linked_edges_list** input_linked_list, struct Edges* input_edge){
    struct linked_edges_list* p = *input_linked_list;
    if (!p)
    {
        p = Create_linked_edges_list(input_edge);
        return;
    }
    
    while (p->next)
    {
        p = p->next;
    }
    p->next = Create_linked_edges_list(input_edge);
}

/* Node */
struct Node
{
    int value;
    int in;
    int out;
    struct linked_nexts_list* nexts;
    struct linked_edges_list* edges;
};

struct Node* create_node(int input_value, int input_in, int input_out){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->nexts = NULL;
    new_node->edges = NULL;
    new_node->value = input_value;
    new_node->in = input_in;
    new_node->out = input_out;
    return new_node;
}

/* node hash */
struct node_pair
{
    int key;
    struct Node* val;
};

struct node_hash
{
    struct node_pair* array;
    int num;
    int capacity;
};

#define HASH_CAPACITY 10

int node_hash_func(int key){
    return key % HASH_CAPACITY;
}

struct node_hash* node_hash_create() {
    struct node_hash* new_hash = malloc(sizeof(struct node_hash));
    if (!new_hash) {
        fprintf(stderr, "ERROR! No more memory");
        exit(EXIT_FAILURE);
    }
    new_hash->array = calloc(HASH_CAPACITY, sizeof(struct node_pair));
    if (!new_hash->array) {
        fprintf(stderr, "ERROR! No more memory");
        free(new_hash);
        exit(EXIT_FAILURE);
    }
    new_hash->num = 0;
    new_hash->capacity = HASH_CAPACITY;
    return new_hash;
}

void node_hash_insert(struct node_hash* h, struct Node* input_node, int input_key) {
    if (h->num == h->capacity) {
        fprintf(stderr, "ERROR! Hash is full");
        return;
    }

    int hash_sit = node_hash_func(input_key);
    int offset = 0;
    while (h->array[hash_sit].key)
    {
        if (offset == HASH_CAPACITY)
        {
            exit(EXIT_FAILURE);
        }
        hash_sit = (hash_sit + ++offset) % HASH_CAPACITY;
    }

    h->array[hash_sit].key = input_key;
    h->array[hash_sit].val = input_node;
    h->num++;
}

struct Node* node_hash_get(struct node_hash* h, int input_key){
    int hash_sit = node_hash_func(input_key);
    int offset = 0;

    int get_key = 0;
    struct Node* get_value = NULL;
    while (1)
    {
        get_key = h->array[hash_sit].key;
        get_value = h->array[hash_sit].val;
        if (!get_value)
        {
            return NULL;
        }

        if (get_key == input_key)
        {
            return get_value;
        }
        
        if (offset == HASH_CAPACITY)
        {
            exit(EXIT_FAILURE);
        }

        hash_sit = (hash_sit + ++offset) % HASH_CAPACITY;
    }
}

void free_hash(struct node_hash* h) {
    if (h) {
        for (int i = 0; i < h->num; i++)
        {
            free(h->array[i].val);
        }
        free(h->array);
        free(h);
    }
}

/* Edge */
struct Edges
{
    int weight;
    struct Node* from;
    struct Node* to;
};

struct Edges* create_edges(int input_weight, struct Node* input_from, struct Node* input_to){
    struct Edges* new_edges = malloc(sizeof(struct Edges));
    new_edges->weight = input_weight;
    new_edges->from = input_from;
    new_edges->to = input_to;
}

/* edge hash */
struct edge_pair
{
    int key;
    struct Edges* val;
};

struct edge_hash
{
    struct edge_pair* array;
    int num;
    int capacity;
};

int edge_hash_func(int key){
    return key % HASH_CAPACITY;
}

struct edge_hash* edge_hash_create() {
    struct edge_hash* new_hash = malloc(sizeof(struct edge_hash));
    if (!new_hash) {
        fprintf(stderr, "ERROR! No more memory");
        exit(EXIT_FAILURE);
    }
    new_hash->array = calloc(HASH_CAPACITY, sizeof(struct edge_pair));
    if (!new_hash->array) {
        fprintf(stderr, "ERROR! No more memory");
        free(new_hash);
        exit(EXIT_FAILURE);
    }
    new_hash->num = 0;
    new_hash->capacity = HASH_CAPACITY;
    return new_hash;
}

void edge_hash_insert(struct edge_hash* h, struct Edges* input_node, int input_key) {
    if (h->num == h->capacity) {
        fprintf(stderr, "ERROR! Hash is full");
        return;
    }

    int hash_sit = node_hash_func(input_key);
    int offset = 0;
    while (h->array[hash_sit].key)
    {
        if (offset == HASH_CAPACITY)
        {
            exit(EXIT_FAILURE);
        }
        hash_sit = (hash_sit + ++offset) % HASH_CAPACITY;
    }

    h->array[hash_sit].key = input_key;
    h->array[hash_sit].val = input_node;
    h->num++;
}

struct Edges* edge_hash_get(struct edge_hash* h, int input_key){
    int hash_sit = node_hash_func(input_key);
    int offset = 0;

    int get_key = 0;
    struct Edges* get_val = NULL;
    while (1)
    {
        get_key = h->array[hash_sit].key;
        get_val = h->array[hash_sit].val;
        if (!get_val)
        {
            return NULL;
        }

        if (get_key == input_key)
        {
            return get_val;
        }
        
        if (offset == HASH_CAPACITY)
        {
            exit(EXIT_FAILURE);
        }

        hash_sit = (hash_sit + ++offset) % HASH_CAPACITY;
    }
}

void edge_hash_free(struct edge_hash* h) {
    if (h) {
        for (int i = 0; i < h->num; i++)
        {
            free(h->array[i].val);
        }
        free(h->array);
        free(h);
    }
}

/* graph */
struct Graph
{
    struct edge_hash* edges;
    struct node_hash* nodes;
};

struct Graph* create_graph(){
    struct Graph* new_graph = malloc(sizeof(struct Graph));
    if (!new_graph)
    {
        fprintf(stderr, "ERROR! No more memory");
        exit(EXIT_FAILURE);
    }
    
    new_graph->edges = edge_hash_create();
    new_graph->nodes = node_hash_create();
    return new_graph;
}

void createGraph(int* input_graph, int num){
    struct Graph* new_graph = create_graph();
    int weight, from, to;
    struct Node* from_node = NULL;
    struct Node* to_node = NULL;
    struct Edges* new_edge = NULL;
    for (int i = 0; i < num; i = i + 3)
    {
        weight = input_graph[i];
        from = input_graph[i + 1];
        to = input_graph[i + 2];

        if (!node_hash_get(new_graph->nodes, from))
        {
            node_hash_insert(new_graph->nodes, create_node(from, 0, 0), from);
        }
        
        if (!node_hash_get(new_graph->nodes, to))
        {
            node_hash_insert(new_graph->nodes, create_node(to, 0, 0), to);
        }
        
        from_node = node_hash_get(new_graph->nodes, from);
        to_node = node_hash_get(new_graph->nodes, to);
        new_edge = create_edges(weight, from_node, to_node);

        Add_linked_nexts_list(&from_node->nexts, to_node);
        from_node->out++;
        to_node->in++;
        Add_linked_edges_list(&from_node->edges, new_edge);
        edge_hash_insert(new_graph->edges, new_edge, weight);
    }
    
}

int main(){
    int matrix[][3] = {
        {5, 0, 1},
        {3, 2, 1},
        {1, 2, 0}
    };

    createGraph((int*)matrix, 3);

    return 0;
}