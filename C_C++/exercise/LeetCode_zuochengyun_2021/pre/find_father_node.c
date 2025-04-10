/*
给定两个二叉树的节点node1和node2，找到他们的最低公共祖先节点
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


struct Pair
{
    Tree key;
    Tree val;
};

struct hash
{
    struct Pair* array;
    int num;
    int capacity;
};

#define HASH_CAPACITY 10

int Hash_func(long long int key){
    return key % HASH_CAPACITY;
}

struct hash* create_hash() {
    struct hash* new_hash = malloc(sizeof(struct hash));
    if (!new_hash) {
        fprintf(stderr, "ERROR! No more memory");
        exit(EXIT_FAILURE);
    }
    new_hash->array = calloc(HASH_CAPACITY, sizeof(struct Pair));
    if (!new_hash->array) {
        fprintf(stderr, "ERROR! No more memory");
        free(new_hash);
        exit(EXIT_FAILURE);
    }
    new_hash->num = 0;
    new_hash->capacity = HASH_CAPACITY;
    return new_hash;
}

void insert_hash(struct hash* h, Tree key, Tree val) {
    if (h->num == h->capacity) {
        fprintf(stderr, "ERROR! Hash is full");
        return;
    }

    int hash_sit = Hash_func((long long)key);
    int offset = 0;
    while (h->array[(hash_sit + offset) % HASH_CAPACITY].key)  // 如果已经有值了
    {
        ++offset;
    }

    h->array[hash_sit + offset].key = key;
    h->array[hash_sit + offset].val = val;
    h->num++;
}

Tree get_hash(struct hash* h, Tree key){
    int hash_sit = Hash_func((long long)key);
    int offset = 0;

    if (!(h->array[hash_sit].key))
    {
        return NULL;
    }
    

    while (h->array[(hash_sit + offset) % HASH_CAPACITY].key != key)
    {
        if (offset == HASH_CAPACITY)
        {
            return NULL;
        }
        ++offset;
    }
    
    return h->array[hash_sit + offset].val;
}

void free_hash(struct hash* h) {
    if (h) {
        for (int i = 0; i < h->num; i++)
        {
            free(h->array[i].key);
        }
        free(h->array);
        free(h);
    }
}

// /* method1 */
void recording_route(struct hash* input_hash, Tree input_root){
    if (!input_root)
    {
        return;
    }
    
    if (input_root->left)
    {
        insert_hash(input_hash, input_root->left, input_root);
    }
    
    if (input_root->right)
    {
        insert_hash(input_hash, input_root->right, input_root);
    }
    
    recording_route(input_hash, input_root->left);
    recording_route(input_hash, input_root->right);
}

Tree get_common_father(Tree root, Tree node1, Tree node2){
    struct hash* hash1 = create_hash();
    
    recording_route(hash1, root);

    Tree n1 = node1;
    struct hash* hash2 = create_hash();
    while (n1)
    {
        insert_hash(hash2, n1, n1);
        n1 = get_hash(hash1, n1);
    }
    
    insert_hash(hash1, root, root);

    Tree n2 = node2;
    Tree result = NULL;
    while (n2)
    {
        n2 = get_hash(hash1, n2);
        result = get_hash(hash2, n2);
        if (result)
        {
            return result;
        }
        
    }
    return NULL;
}

// /* method2 */
Tree lowestAncestor(Tree root, Tree node1, Tree node2){
    if (!root || root == node1 || root == node2)
    {
        return root;
    }

    Tree left = lowestAncestor(root->left, node1, node2);
    Tree right = lowestAncestor(root->right, node1, node2);

    if (left && right)
    {
        return root;
    }
    
    return left ? left : right;
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

    Tree result = get_common_father(t1, t2, t3);
    printf("\nt1: %d\n", result->value);

    result = get_common_father(t10, t40, t50);
    printf("\nt10: %d\n", result->value);

    result = get_common_father(t100, t600, t800);
    printf("\nt100: %d\n", result->value);

    result = get_common_father(t1, t6, t7);
    printf("\nt1: %d\n", result->value);

    result = lowestAncestor(t1, t2, t3);
    printf("\nt1: %d\n", result->value);

    result = lowestAncestor(t10, t40, t50);
    printf("\nt10: %d\n", result->value);

    result = lowestAncestor(t100, t600, t800);
    printf("\nt100: %d\n", result->value);

    result = lowestAncestor(t1, t6, t7);
    printf("\nt1: %d\n", result->value);

    return 0;
}