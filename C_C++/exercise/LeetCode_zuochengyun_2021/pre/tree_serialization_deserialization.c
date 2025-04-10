/*
二叉树序列化和反序列化
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Elementtype;

struct binary_tree{
    Elementtype value;
    struct binary_tree* left;
    struct binary_tree* right;
    struct binary_tree* parent;
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
    new_tree->parent = NULL;
    return new_tree;
}

Tree ADD_left(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->left = new_tree;
    new_tree->parent = input_array;
    return new_tree;
}

Tree ADD_right(Tree input_array, Elementtype val){
    Tree new_tree = Create(val);
    input_array->right = new_tree;
    new_tree->parent = input_array;
    return new_tree;
}


#define QUEUE_Capacity 100
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
        return NULL;
    }
    
    Tree output = (input_queue->array)[input_queue->head++];
    --input_queue->size;
    input_queue->head = input_queue->head > -1? input_queue->head : (input_queue->head + QUEUE_Capacity) % QUEUE_Capacity;
    return output;
}

bool Queue_isempty(myqueue input_queue){
    return input_queue->size == 0? true : false;
}


// Binary tree sequence number,二叉树序列化
#define CHAR_NUM 100
#define TMP_NUM 10
int tree_sequence(Tree input_array, char* char_array, int i){
    if (!input_array)
    {
        strncpy(char_array + i, "#_", 2);
        i += 2;
        return i;
    }
    
    itoa(input_array->value, char_array + i, 10);
    char_array[i + 1] = '_';
    i += 2;

    i = tree_sequence(input_array->left, char_array, i);
    i = tree_sequence(input_array->right, char_array, i);
}

// Binary tree deserialization,二叉树反序列化
myqueue process(char* char_array, int num){
    char tmp_array[TMP_NUM] = {0};
    myqueue new_queue = Queue_init();
    int i = 0;
    Tree new_tree;
    while (i < num)
    {
        if (char_array[i] != '#')
        {
            int j = 0;
            for (; char_array[i + j] != '_'; j++)
            {
                tmp_array[j] = char_array[i + j];
            }
            tmp_array[i + j] = '\0';
            int val = atoi(tmp_array);
            new_tree = Create(val);
            Queue_add(new_queue, new_tree);

            i += j + 1;
        }else
        {
            Queue_add(new_queue, NULL);
            i += 2;
        }
    }
    return new_queue;
}

Tree tree_deserialization(myqueue input_queue){
    Tree new_tree;
    if (!(new_tree = Queue_out(input_queue)))
    {
        return NULL;
    }
    
    new_tree->left = tree_deserialization(input_queue);
    new_tree->right = tree_deserialization(input_queue);
    return new_tree;
}



int main(){
    Tree t1 = Create(1);
    Tree t2 = ADD_left(t1, 2);
    Tree t3 = ADD_right(t1, 3);
    Tree t4 = ADD_left(t2, 4);
    Tree t5 = ADD_right(t2, 5);
    Tree t6 = ADD_left(t3, 6);
    Tree t7 = ADD_right(t3, 7);

    Tree t10 = Create(1);
    Tree t20 = ADD_left(t10, 2);
    Tree t30 = ADD_right(t10, 3);
    Tree t40 = ADD_left(t20, 4);
    Tree t50 = ADD_right(t20, 5);
    Tree t70 = ADD_right(t30, 7);

    Tree t100 = Create(1);
    Tree t200 = ADD_left(t100, 2);
    Tree t300 = ADD_right(t100, 3);
    Tree t400 = ADD_left(t200, 4);
    Tree t500 = ADD_right(t200, 5);
    Tree t600 = ADD_left(t300, 6);
    Tree t800 = ADD_left(t400, 8);

    char input_char[CHAR_NUM] = {0};
    tree_sequence(t1, input_char, 0);
    printf("\nt1: %s\n", input_char);

    myqueue get_queue = process(input_char, strlen(input_char));
    Tree get_tree = tree_deserialization(get_queue);
    printf("\n");

    return 0;
}