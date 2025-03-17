/*
打印链表
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

void preOrder_recursion(Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    printf("%4d", input_array->value);
    preOrder_recursion(input_array->left);
    preOrder_recursion(input_array->right);
}

void inOrder_recursion(Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    inOrder_recursion(input_array->left);
    printf("%4d", input_array->value);
    inOrder_recursion(input_array->right);
}

void postOrder_recursion(Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    postOrder_recursion(input_array->left);
    postOrder_recursion(input_array->right);
    printf("%4d", input_array->value);
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

void preOrder_stack1(Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    Tree stack_array[STACK_CAPACITY];
    struct stack stack1 = {
        .array = stack_array,
        .size = -1,
        .capacity = STACK_CAPACITY,
    };

    Tree root = input_array;
    Stack_add(&stack1, root);
    while (stack1.size != -1)
    {
        root = Stack_out(&stack1);
        printf("%4d", root->value);

        if (root->right != NULL)
        {
            Stack_add(&stack1, root->right);
        }

        if (root->left != NULL)
        {
            Stack_add(&stack1, root->left);
        }
    }
}

void preOrder_stack2(Tree input_array){
    if (!input_array)
    {
        return;
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
            printf("%4d", root->value);
            root = root->left;
        }else
        {
            root = Stack_out(&stack1);
            root = root->right;
        }

    }
}

void inOrder_stack(Tree input_array){
    if (!input_array)
    {
        return;
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
            printf("%4d", root->value);
            root = root->right;
        }

    }
}

void postOrder_stack(Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    Tree stack_array1[STACK_CAPACITY];
    struct stack stack1 = {
        .array = stack_array1,
        .size = -1,
        .capacity = STACK_CAPACITY,
    };
    Tree stack_array2[STACK_CAPACITY];
    struct stack stack2 = {
        .array = stack_array2,
        .size = -1,
        .capacity = STACK_CAPACITY,
    };

    Tree root = input_array;
    Stack_add(&stack1, root);
    while (!Stack_isempty(&stack1))
    {
        root = Stack_out(&stack1);
        Stack_add(&stack2, root);

        if (root->left != NULL)
        {
            Stack_add(&stack1, root->left);
        }

        if (root->right != NULL)
        {
            Stack_add(&stack1, root->right);
        }
    }

    while (!Stack_isempty(&stack2))
    {
        root = Stack_out(&stack2);
        printf("%4d", root->value);
    }
    
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

// BFS,Breath-first-search,宽度优先遍历
void BFS_stack(Tree input_array){
    if (!input_array)
    {
        return;
    }
    
    myqueue queue = Queue_init();

    Tree root = input_array;
    Queue_add(queue, root);
    while (!Queue_isempty(queue))
    {
        root = Queue_out(queue);
        printf("%4d", root->value);

        if (root->left != NULL)
        {
            Queue_add(queue, root->left);
        }

        if (root->right != NULL)
        {
            Queue_add(queue, root->right);
        }
    }
}

int main(){
    Tree t1 = Create(0);
    Tree t2 = ADD_left(t1, 1);
    Tree t3 = ADD_right(t1, 2);
    Tree t4 = ADD_left(t2, 3);
    Tree t5 = ADD_right(t2, 4);

    printf("递归:\n");
    printf("前序遍历\t");
    preOrder_recursion(t1);
    printf("\n中序遍历\t");
    inOrder_recursion(t1);
    printf("\n后序遍历\t");
    postOrder_recursion(t1);
    printf("\n\n");

    printf("非递归:\n");
    printf("前序遍历1\t");
    preOrder_stack1(t1);
    printf("\n前序遍历2\t");
    preOrder_stack2(t1);
    printf("\n中序遍历\t");
    inOrder_stack(t1);
    printf("\n后序遍历\t");
    postOrder_stack(t1);
    printf("\n\n");

    printf("宽度优先遍历\t");
    BFS_stack(t1);
    return 0;
}