/*
层序遍历
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Elementtype;

struct binary_tree{
    Elementtype value;
    struct binary_tree* left;
    struct binary_tree* right;
};

typedef struct binary_tree* Tree;

Tree Create(Elementtype val){
    Tree new_tree = malloc(sizeof(struct binary_tree));
    if (!new_tree)
    {
        fprintf(stderr, "ERROR!no more memory");
        exit(EXIT_FAILURE);
    }
    new_tree->value = val;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

Tree ADD_left(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->left = new_tree;
    return new_tree;
}

Tree ADD_right(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->right = new_tree;
    return new_tree;
}

#define QUEUE_Capacity 10
struct queue{
   Tree* array;
   int head;
   int end;
   int size;
   int Capacity;
};

typedef struct queue* myqueue;

myqueue Queue_init(){
    myqueue new_queue = malloc(sizeof(struct queue));
    new_queue->array = malloc(sizeof(Tree) * QUEUE_Capacity);
    new_queue->head = 0;
    new_queue->end = 0;
    new_queue->size = 0;
    new_queue->Capacity = QUEUE_Capacity;
    return new_queue;
}

void Queue_add(myqueue input_queue, Tree input_tree){
    if (input_queue->size == QUEUE_Capacity)
    {
        fprintf(stderr, "error queue add!");
        exit(EXIT_FAILURE);
    }

    (input_queue->array)[input_queue->end++] = input_tree;
    ++input_queue->size;
    input_queue->end = input_queue->end < QUEUE_Capacity? input_queue->end : input_queue->end % QUEUE_Capacity;
}

Tree Queue_out(myqueue input_queue){
    if (input_queue->size == 0)
    {
        fprintf(stderr, "error queue out!");
        exit(EXIT_FAILURE);
    }
    
    Tree output = (input_queue->array)[input_queue->head++];
    --input_queue->size;
    input_queue->head = input_queue->head > -1? input_queue->head : (input_queue->head + QUEUE_Capacity) % QUEUE_Capacity;
    return output;
}

bool Queue_isempty(myqueue input_queue){
    return input_queue->size == 0? true : false;
}

// level-order traversal,LOT, 层序遍历
int LOT_max_width(Tree input_array){
    if (!input_array)
    {
        return -1;
    }
    
    myqueue queue1 = Queue_init();
    Tree root = input_array;
    Queue_add(queue1, root);
    int max_width = 0;
    int cur_level_width = 1;
    Tree node_cur_end = input_array;
    Tree node_next_end = NULL;
    while (!Queue_isempty(queue1))
    {
        root = Queue_out(queue1);
        printf("%4d", root->value);

        if (root->left != NULL)
        {
            Queue_add(queue1, root->left);
            node_next_end = root->left;
        }
        
        if (root->right != NULL)
        {
            Queue_add(queue1, root->right);
            node_next_end = root->right;
        }
        
        if (node_cur_end != root)
        {
            ++cur_level_width;
        }else
        {
            max_width = ++cur_level_width > max_width ? cur_level_width : max_width;
            cur_level_width = 0;
            node_cur_end = node_next_end;
            node_next_end = NULL;
        }
        

    }

    return cur_level_width > max_width ? cur_level_width : max_width;
}

int main(){
    Tree t1 = Create(0);
    Tree t2 = ADD_left(t1, 1);
    Tree t3 = ADD_right(t1, 2);
    Tree t4 = ADD_left(t2, 3);
    Tree t5 = ADD_right(t2, 4);
    Tree t6 = ADD_left(t3, 5);
    Tree t7 = ADD_right(t3, 6);

    // 层序遍历
    printf("\n层序遍历: ");
    int result = LOT_max_width(t1);
    printf("\nmax width: %d\n", result);
    return 0;
}