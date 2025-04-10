/*
判断是不是搜索二叉树
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

#define STACK_CAPACITY 10
struct stack{
    Tree* array;
    int size;
    int capacity;
};

typedef struct stack* mystack;

void Stack_add(mystack input_stack, Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    input_stack->array[++input_stack->size] = input_array;
}

Tree Stack_out(mystack input_stack){
    if ((*input_stack).size == -1)
    {
        return NULL;
    }
    
    Tree tmp_array = (*input_stack).array[((*input_stack).size)--];
    return tmp_array;
}

bool Stack_isempty(mystack input_stack){
    return input_stack->size == -1 ? true : false;
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

// 利用几个变量，判断是否是二叉搜索树
int pre_val;
bool isBST1(Tree input_array){
    if (input_array == NULL)
    {
        return true;
    }
    
    bool result = isBST1(input_array->left);
    if (!result)
    {
        return false;
    }
    
    if (input_array->value < pre_val)
    {
        return false;
    }else
    {
        pre_val = input_array->value;
    }
    
    return isBST1(input_array->right);
}

// 利用队列，判断是否是二叉搜索树
myqueue queue1 = NULL;
void process(Tree input_array){
    if (input_array == NULL)
    {
        return;
    }
    
    process(input_array->left);
    Queue_add(queue1, input_array);
    process(input_array->right);
}

bool isBST2(Tree input_array){
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

// 利用栈，判断是否是二叉搜索树
bool isBST3(Tree input_array){
    if (!input_array)
    {
        return true;
    }
    
    Tree stack_array[STACK_CAPACITY];
    struct stack stack1 = {
        .array = stack_array,
        .size = -1,
        .capacity = STACK_CAPACITY,
    };

    Tree root = input_array;
    while (root != NULL || !Stack_isempty(&stack1))
    {
        if (root != NULL)
        {
            Stack_add(&stack1, root);
            root = root->left;
        }else
        {
            root = Stack_out(&stack1);
            if (pre_val >= root->value)
            {
                return false;
            }else
            {
                pre_val = root->value;
            }
            
            root = root->right;
        }

    }
    return true;
}

/* method2 */
#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)
struct data
{
    bool isbalance;
    int max;
    int min;
};

struct data* mydata_init(bool isbalance, int max, int min){
    struct data* new_data = malloc(sizeof(struct data));
    if (!new_data)
    {
        fprintf(stderr, "no more memory!");
        exit(EXIT_FAILURE);
    }
    
    new_data->isbalance = isbalance;
    new_data->max = max;
    new_data->min = min;
    return new_data;
}

// balanced binary tree,bbt,平衡二叉树
struct data* isBST4(Tree input_array){
    if (!input_array)
    {
        return NULL;
    }
    
    struct data* left = isBST4(input_array->left);
    struct data* right = isBST4(input_array->right);

    int max = input_array->value;
    int min = input_array->value;
    if (left)
    {
        max = MAX(left->max, max);
        // min = MIN(left->min, min);
    }

    if (right)
    {
        // max = MAX(right->max, max);
        min = MIN(right->min, min);
    }
    
    /* method 1 */
    // bool isbalanced = true;
    // if (left && (left->max >= input_array->value || !left->isbalance))
    // {
    //     isbalanced = false;
    // }
    
    // if (right && (right->min <= input_array->value || !right->isbalance))
    // {
    //     isbalanced = false;
    // }

    /* method 2 */
    
    bool isbalanced = false;
    if ((left ? (left->max < input_array->value && left->isbalance) : true)
        &&
        (right ? (right->min > input_array->value && right->isbalance) : true))
    {
        isbalanced = true;
    }
    
    

    return mydata_init(isbalanced, max, min);
}

bool start1(Tree input_array){
    return isBST4(input_array)->isbalance;
}

int main(){
    // 是搜索二叉树
    Tree t1 = Create(10);
    Tree t2 = ADD_left(t1, 5);
    Tree t3 = ADD_right(t1, 15);
    Tree t4 = ADD_left(t2, 4);
    Tree t5 = ADD_right(t2, 7);
    Tree t6 = ADD_left(t3, 12);
    Tree t7 = ADD_right(t3, 20);

    // 不是搜索二叉树
    Tree t10 = Create(20);
    Tree t20 = ADD_left(t10, 10);
    Tree t30 = ADD_right(t10, 30);
    Tree t40 = ADD_left(t20, 5);
    Tree t50 = ADD_right(t20, 15);
    Tree t60 = ADD_left(t30, 5);
    Tree t70 = ADD_right(t30, 15);

    pre_val = INT_MIN;
    int result = isBST1(t1);
    printf("isBST1: %d\n", result);

    pre_val = INT_MIN;
    result = isBST1(t10);
    printf("isBST1: %d\n", result);

    pre_val = INT_MIN;
    result = isBST2(t1);
    printf("isBST2: %d\n", result);

    pre_val = INT_MIN;
    result = isBST2(t10);
    printf("isBST2: %d\n", result);

    pre_val = INT_MIN;
    result = isBST3(t1);
    printf("isBST3: %d\n", result);

    pre_val = INT_MIN;
    result = isBST3(t10);
    printf("isBST3: %d\n", result);

    
    result = start1(t1);
    printf("isBST4: %d\n", result);

    result = start1(t10);
    printf("isBST4: %d\n", result);
    return 0;
}