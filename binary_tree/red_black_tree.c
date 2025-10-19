/*
Program Name: Red-Black Tree Implementation
Problem Statement: Implement a Red-Black Tree in C with insertion and inorder traversal.

Sample Input:
Enter number of nodes: 7
Enter values:
10 20 30 15 25 5 1

Sample Output:
Inorder Traversal:
1(B) 5(R) 10(B) 15(B) 20(B) 25(R) 30(B)

Time Complexity:

-> Insertion: O(log n)
-> Search: O(log n)
*/

#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

// Node structure
struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
};

// create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;  // a new node is always red at first
    node->left = node->right = node->parent = NULL;
    return node;
}

// left rotation
void leftRotate(struct Node **root, struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// right rotation
void rightRotate(struct Node **root, struct Node *y) {
    struct Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fix violations after insertion
void fixViolation(struct Node **root, struct Node *z) {
    while (z != *root && z->parent->color == RED) {
        struct Node *parent = z->parent;
        struct Node *grandparent = parent->parent;

        // Case 1: Parent is left child of grandparent
        if (parent == grandparent->left) {
            struct Node *uncle = grandparent->right;

            // Case 1.1: Uncle is red -> Recolor
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // Case 1.2: Node is right child -> Left rotation
                if (z == parent->right) {
                    z = parent;
                    leftRotate(root, z);
                }
                // Case 1.3: Node is left child -> Right rotation
                parent->color = BLACK;
                grandparent->color = RED;
                rightRotate(root, grandparent);
            }
        }
        // Case 2: Parent is right child of grandparent
        else {
            struct Node *uncle = grandparent->left;

            // Case 2.1: Uncle is red -> Recolor
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // Case 2.2: Node is left child -> Right rotation
                if (z == parent->left) {
                    z = parent;
                    rightRotate(root, z);
                }
                // Case 2.3: Node is right child -> Left rotation
                parent->color = BLACK;
                grandparent->color = RED;
                leftRotate(root, grandparent);
            }
        }
    }
    (*root)->color = BLACK; // Root is always black
}

// Insert new node 
void insert(struct Node **root, int data) {
    struct Node *z = newNode(data);
    struct Node *y = NULL;
    struct Node *x = *root;

    // insertion
    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    // Fix RBT property 
    fixViolation(root, z);
}

// Inorder traversal
void inorder(struct Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&root, val);
    }

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    return 0;
}

