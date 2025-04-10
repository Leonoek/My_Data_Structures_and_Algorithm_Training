/*
判断是否是完全二叉树
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

// complete binary tree,CBT,完全二叉树
int isCBT(Tree input_array){
    if (!input_array)
    {
        return -1;
    }
    
    myqueue queue1 = Queue_init();
    Tree root = input_array;
    Queue_add(queue1, root);
    bool flag = false;
    Tree left = NULL;
    Tree right = NULL;
    while (!Queue_isempty(queue1))
    {
        root = Queue_out(queue1);
        printf("%4d", root->value);
        left = root->left;
        right = root->right;

        if (left != NULL)
        {
            Queue_add(queue1, left);
        }
        
        if (right != NULL)
        {
            Queue_add(queue1, right);
        }

        if ((left == NULL) && right != NULL || (flag && (left || right)) )
        {
            return false;
        }

        if ((left == NULL) || (right == NULL))
        {
            flag = true;
        }
    }

    return true;
}

int main(){
    Tree t1 = Create(0);
    Tree t2 = ADD_left(t1, 1);
    Tree t3 = ADD_right(t1, 2);
    Tree t4 = ADD_left(t2, 3);
    Tree t5 = ADD_right(t2, 4);
    Tree t6 = ADD_left(t3, 5);
    Tree t7 = ADD_right(t3, 6);

    Tree t10 = Create(0);
    Tree t20 = ADD_left(t10, 1);
    Tree t30 = ADD_right(t10, 2);
    Tree t40 = ADD_left(t20, 3);
    Tree t50 = ADD_right(t20, 4);
    Tree t70 = ADD_right(t30, 6);

    Tree t100 = Create(0);
    Tree t200 = ADD_left(t100, 1);
    Tree t300 = ADD_right(t100, 2);
    Tree t400 = ADD_left(t200, 3);
    Tree t500 = ADD_right(t200, 4);
    Tree t600 = ADD_left(t300, 5);
    Tree t800 = ADD_left(t400, 6);

    int result = isCBT(t1);
    printf("\nt1 isCBT: %d\n", result);

    result = isCBT(t10);
    printf("\nt10 isCBT: %d\n", result);

    result = isCBT(t100);
    printf("\nt100 isCBT: %d\n", result);
    return 0;
}