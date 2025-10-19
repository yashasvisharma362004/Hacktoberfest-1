/*
Program Name: AVL Tree Implementation
Problem Statement: an AVL Tree with insertion and balancing.

Sample Input:
Enter number of nodes to insert: 7
Enter elements: 30 20 40 10 25 50 5

Sample Output:
Inorder traversal:
5 10 20 25 30 40 50

Time Complexity:
-> Insertion: O(log n)
-> Search: O(log n)
-? Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// find height
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// find maxm 
int max(int a, int b) {
    return (a > b) ? a : b;
}

// new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // initialised at leaf
    return node;
}

// Right rotation 
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // rotate
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // rotate
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Balance factor
int getBalance(struct Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// insert a key and balance the tree
struct Node* insert(struct Node* node, int key) {
    // 1. insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // unique keys

    // 2. Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Check balance factor
    int balance = getBalance(node);

    // If unbalanced, the following cases arise:

    // Left Left 
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right 
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right 
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left 
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    return 0;
}

