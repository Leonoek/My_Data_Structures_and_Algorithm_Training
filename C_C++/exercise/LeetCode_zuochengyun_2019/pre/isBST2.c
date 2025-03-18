/*
打印链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

// 判断是否是二叉搜索树
myqueue queue1 = NULL;
int pre_val;
void process(Tree input_array){
    if (input_array == NULL)
    {
        return;
    }
    
    process(input_array->left);
    Queue_add(queue1, input_array);
    process(input_array->right);
}

bool isBST(Tree input_array){
    queue1 = Queue_init();
    process(input_array);
    Tree node = NULL;
    while (!Queue_isempty(queue1))
    {
        node = Queue_out(queue1);
        if (pre_val > node->value)
        {
            return false;
        }else
        {
            pre_val = node->value;
        }
    }
    return true;
}

int main(){
    Tree t1 = Create(10);
    Tree t2 = ADD_left(t1, 5);
    Tree t3 = ADD_right(t1, 15);
    Tree t4 = ADD_left(t2, 4);
    Tree t5 = ADD_right(t2, 7);
    Tree t6 = ADD_left(t3, 12);
    Tree t7 = ADD_right(t3, 20);

    pre_val = INT_MIN;
    int result = isBST(t1);
    printf("%d\n", result);

    Tree t10 = Create(20);
    Tree t20 = ADD_left(t10, 10);
    Tree t30 = ADD_right(t10, 30);
    Tree t40 = ADD_left(t20, 5);
    Tree t50 = ADD_right(t20, 15);
    Tree t60 = ADD_left(t30, 5);
    Tree t70 = ADD_right(t30, 15);
    pre_val = INT_MIN;
    result = isBST(t10);
    printf("%d\n", result);
    return 0;
}