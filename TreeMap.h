#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define LONG 1
#define VOID 2

typedef struct Node Node;
struct Node {
    Node *left;
    Node *right;
    void *key;
    void *value;
};
struct mylong {
    long x;
};

typedef struct {
    int (*comp) (void *first, void *second);
    Node **head;
    unsigned int key_type;
    unsigned int value_type;
} TreeMap;

static Node **TM_find(Node **curr, void *key, unsigned int type);

Node *TM_set(TreeMap *op, void *key, void *val) {
    Node ***place;
    if (op->head == NULL) {
        place = &(op->head);
    }
    else {
        Node **to_insert = TM_find(op->head, key, op->key_type);
        place = &to_insert;
    }

    assert(place != NULL);

    if (*place != NULL && **place != NULL) {
        (**place)->value = val;
        return **place;
    }

    Node *new_node;
    if (op->head != NULL) {
        printf("pointing to addy: %p\n", &((*(op->head))->right)); // here *places = &((*(op->head))->right)
        new_node = malloc(sizeof(Node));
        printf("pointing to addy: %p\n", &((*(op->head))->right)); // here &((*(op->head))->right) becomes smthn else
    }
    else {
        new_node = malloc(sizeof(Node));
    }

    *place = &new_node;

    new_node->value = val;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void *TM_get(TreeMap *op, void *key) {
    Node **found = (TM_find(op->head, key, op->key_type));
    return (*found)->value;
}

static Node **TM_find(Node **curr, void *key, unsigned int type) {
    switch (type) {
        case LONG: {
            long d = (*curr)->key;
            long k = (long) key;
            if (d == k)
                return curr;
            else if ((*curr)->right != NULL && k > d)
                return TM_find(&((*curr)->right), key, type);
            else if ((*curr)->left != NULL && k < d)
                return TM_find(&((*curr)->left), key, type);
            else if (k > d)
                return &((*curr)->right);
            else
                return &((*curr)->left);
            break;
        }
    }
    return NULL;
}




