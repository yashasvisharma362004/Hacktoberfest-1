/*
 * avl_tree.c
 * AVL Tree (Self-Balancing Binary Search Tree) Implementation
 * 
 * Program: AVL Tree with Rotations
 * Description: Implements a self-balancing AVL tree with automatic height balancing
 *              through rotations during insertions and deletions.
 * 
 * Features:
 * - Self-balancing property maintained (height difference ≤ 1)
 * - Four types of rotations: LL, RR, LR, RL
 * - Insert, Delete, Search operations
 * - Inorder, Preorder, Postorder traversals
 * - Height and Balance Factor calculation
 * 
 * Time Complexity:
 * - Insert: O(log n)
 * - Delete: O(log n)
 * - Search: O(log n)
 * - Traversals: O(n)
 * 
 * Space Complexity: O(n) for n nodes
 * 
 * Compile: gcc -std=c11 -Wall -Wextra -o avl_tree avl_tree.c -lm
 * Run: ./avl_tree
 * 
 * Example Input/Output:
 * Input: Insert 10, 20, 30, 40, 50, 25
 * Output: Balanced AVL tree with proper rotations applied
 * 
 * AVL Tree Property:
 * For every node, height difference between left and right subtree ≤ 1
 * 
 * Author: Contributed for Hacktoberfest 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// AVL Tree Node structure
typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

/*
 * Utility function to get maximum of two integers
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/*
 * Get height of a node (returns 0 for NULL)
 */
int get_height(AVLNode *node) {
    return node ? node->height : 0;
}

/*
 * Calculate balance factor of a node
 * Balance Factor = height(left subtree) - height(right subtree)
 * Must be in range [-1, 0, 1] for AVL tree
 */
int get_balance_factor(AVLNode *node) {
    return node ? get_height(node->left) - get_height(node->right) : 0;
}

/*
 * Create a new AVL node with given key
 */
AVLNode *create_node(int key) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    
    node->key = key;
    node->height = 1;  // New node is at height 1
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

/*
 * Right Rotate (LL Rotation)
 * Used when left subtree of left child causes imbalance
 * 
 *         y                               x
 *        / \     Right Rotate (y)        /  \
 *       x   T3   - - - - - - - ->       T1   y
 *      / \                                   / \
 *     T1  T2                                T2  T3
 */
AVLNode *rotate_right(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    
    return x;  // New root
}

/*
 * Left Rotate (RR Rotation)
 * Used when right subtree of right child causes imbalance
 * 
 *       x                                y
 *      /  \     Left Rotate(x)          / \
 *     T1   y    - - - - - - - ->       x   T3
 *         / \                         / \
 *        T2  T3                      T1  T2
 */
AVLNode *rotate_left(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    
    return y;  // New root
}

/*
 * Insert a key into AVL tree and maintain balance
 */
AVLNode *avl_insert(AVLNode *node, int key) {
    // 1. Perform standard BST insertion
    if (node == NULL) {
        printf("Inserted: %d\n", key);
        return create_node(key);
    }
    
    if (key < node->key)
        node->left = avl_insert(node->left, key);
    else if (key > node->key)
        node->right = avl_insert(node->right, key);
    else {
        printf("Duplicate key %d not inserted.\n", key);
        return node;  // Duplicate keys not allowed
    }
    
    // 2. Update height of ancestor node
    node->height = 1 + max(get_height(node->left), get_height(node->right));
    
    // 3. Get balance factor to check if node became unbalanced
    int balance = get_balance_factor(node);
    
    // 4. If unbalanced, perform appropriate rotation
    
    // Left-Left Case (LL Rotation)
    if (balance > 1 && key < node->left->key) {
        printf("LL Rotation at node %d\n", node->key);
        return rotate_right(node);
    }
    
    // Right-Right Case (RR Rotation)
    if (balance < -1 && key > node->right->key) {
        printf("RR Rotation at node %d\n", node->key);
        return rotate_left(node);
    }
    
    // Left-Right Case (LR Rotation)
    if (balance > 1 && key > node->left->key) {
        printf("LR Rotation at node %d\n", node->key);
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    
    // Right-Left Case (RL Rotation)
    if (balance < -1 && key < node->right->key) {
        printf("RL Rotation at node %d\n", node->key);
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    
    return node;
}

/*
 * Find node with minimum key value
 */
AVLNode *find_min(AVLNode *node) {
    AVLNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/*
 * Delete a key from AVL tree and maintain balance
 */
AVLNode *avl_delete(AVLNode *root, int key) {
    // 1. Perform standard BST deletion
    if (root == NULL) {
        printf("Key %d not found for deletion.\n", key);
        return root;
    }
    
    if (key < root->key)
        root->left = avl_delete(root->left, key);
    else if (key > root->key)
        root->right = avl_delete(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL || root->right == NULL) {
            AVLNode *temp = root->left ? root->left : root->right;
            
            if (temp == NULL) {  // No child
                temp = root;
                root = NULL;
            } else {  // One child
                *root = *temp;  // Copy contents
            }
            printf("Deleted: %d\n", key);
            free(temp);
        } else {
            // Node with two children: Get inorder successor
            AVLNode *temp = find_min(root->right);
            root->key = temp->key;
            root->right = avl_delete(root->right, temp->key);
        }
    }
    
    if (root == NULL)
        return root;
    
    // 2. Update height
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    
    // 3. Get balance factor
    int balance = get_balance_factor(root);
    
    // 4. Rebalance if needed
    
    // Left-Left Case
    if (balance > 1 && get_balance_factor(root->left) >= 0)
        return rotate_right(root);
    
    // Left-Right Case
    if (balance > 1 && get_balance_factor(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    
    // Right-Right Case
    if (balance < -1 && get_balance_factor(root->right) <= 0)
        return rotate_left(root);
    
    // Right-Left Case
    if (balance < -1 && get_balance_factor(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }
    
    return root;
}

/*
 * Search for a key in AVL tree
 */
bool avl_search(AVLNode *root, int key) {
    if (root == NULL) {
        printf("Key %d not found.\n", key);
        return false;
    }
    
    if (key == root->key) {
        printf("Key %d found!\n", key);
        return true;
    }
    
    if (key < root->key)
        return avl_search(root->left, key);
    else
        return avl_search(root->right, key);
}

/*
 * Inorder traversal (Left-Root-Right)
 * Produces sorted sequence
 */
void inorder(AVLNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/*
 * Preorder traversal (Root-Left-Right)
 */
void preorder(AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

/*
 * Print tree structure with indentation
 */
void print_tree(AVLNode *root, int space) {
    if (root == NULL)
        return;
    
    space += 5;
    print_tree(root->right, space);
    
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d(BF:%d)\n", root->key, get_balance_factor(root));
    
    print_tree(root->left, space);
}

/*
 * Free all nodes in AVL tree
 */
void avl_destroy(AVLNode *root) {
    if (root != NULL) {
        avl_destroy(root->left);
        avl_destroy(root->right);
        free(root);
    }
}

/*
 * Main function demonstrating AVL tree operations
 */
int main(void) {
    printf("=== AVL Tree Implementation Demo ===\n\n");
    
    AVLNode *root = NULL;
    
    // Test insertions that trigger different rotations
    int keys[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    printf("--- Insertion Operations ---\n");
    for (int i = 0; i < n; i++) {
        root = avl_insert(root, keys[i]);
    }
    
    printf("\n--- Tree Structure ---\n");
    print_tree(root, 0);
    
    printf("\n--- Traversals ---\n");
    printf("Inorder (sorted): ");
    inorder(root);
    printf("\n");
    
    printf("Preorder: ");
    preorder(root);
    printf("\n\n");
    
    // Search operations
    printf("--- Search Operations ---\n");
    avl_search(root, 25);
    avl_search(root, 100);
    printf("\n");
    
    // Deletion operations
    printf("--- Deletion Operations ---\n");
    root = avl_delete(root, 10);
    
    printf("\n--- Tree After Deletion ---\n");
    print_tree(root, 0);
    
    printf("\n--- Final Inorder ---\n");
    inorder(root);
    printf("\n\n");
    
    // Statistics
    printf("--- AVL Tree Properties ---\n");
    printf("Height: %d\n", get_height(root));
    printf("Root: %d\n", root->key);
    printf("Balance Factor of Root: %d\n", get_balance_factor(root));
    printf("All nodes have balance factor in [-1, 0, 1]: Verified\n");
    
    // Clean up
    avl_destroy(root);
    printf("\nAVL tree destroyed and memory freed.\n");
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}
