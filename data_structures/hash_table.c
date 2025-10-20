/*
 * hash_table.c
 * Hash Table implementation with chaining for collision resolution
 * 
 * Program: Hash Table with Separate Chaining
 * Description: Implements a hash table data structure using separate chaining
 *              to handle collisions. Supports insert, search, delete operations.
 * 
 * Features:
 * - Dynamic hash table with linked list chains
 * - Basic hash function using modulo
 * - Insert, Search, Delete, and Display operations
 * - Memory-safe with proper cleanup
 * 
 * Time Complexity:
 * - Average Case: O(1) for insert, search, delete
 * - Worst Case: O(n) when all keys hash to same bucket
 * 
 * Space Complexity: O(n) where n is number of elements
 * 
 * Compile: gcc -std=c11 -Wall -Wextra -o hash_table hash_table.c
 * Run: ./hash_table
 * 
 * Example Input/Output:
 * Input: Insert keys: 15, 25, 35, 45
 * Output: Hash Table structure with chains at appropriate indices
 * 
 * Author: Contributed for Hacktoberfest 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// Node structure for chaining
typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

// Hash Table structure
typedef struct HashTable {
    Node **buckets;  // Array of linked list heads
    int size;
} HashTable;

/*
 * Hash function using modulo method
 * Returns index in range [0, TABLE_SIZE-1]
 */
int hash_function(int key) {
    return abs(key) % TABLE_SIZE;
}

/*
 * Create a new node with given key-value pair
 */
Node *create_node(int key, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

/*
 * Initialize hash table with given size
 */
HashTable *create_hash_table(int size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (!table) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    
    table->size = size;
    table->buckets = (Node **)calloc(size, sizeof(Node *));
    if (!table->buckets) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(table);
        return NULL;
    }
    
    return table;
}

/*
 * Insert key-value pair into hash table
 * If key exists, update the value
 */
bool hash_insert(HashTable *table, int key, int value) {
    if (!table) return false;
    
    int index = hash_function(key);
    Node *current = table->buckets[index];
    
    // Check if key already exists (update value)
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            printf("Updated: Key %d -> Value %d (at index %d)\n", key, value, index);
            return true;
        }
        current = current->next;
    }
    
    // Insert new node at the beginning of the chain
    Node *new_node = create_node(key, value);
    if (!new_node) return false;
    
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    
    printf("Inserted: Key %d -> Value %d (at index %d)\n", key, value, index);
    return true;
}

/*
 * Search for a key in hash table
 * Returns value if found, -1 otherwise
 */
int hash_search(HashTable *table, int key) {
    if (!table) return -1;
    
    int index = hash_function(key);
    Node *current = table->buckets[index];
    
    while (current != NULL) {
        if (current->key == key) {
            printf("Found: Key %d -> Value %d (at index %d)\n", key, current->value, index);
            return current->value;
        }
        current = current->next;
    }
    
    printf("Key %d not found!\n", key);
    return -1;
}

/*
 * Delete a key from hash table
 * Returns true if deleted, false if not found
 */
bool hash_delete(HashTable *table, int key) {
    if (!table) return false;
    
    int index = hash_function(key);
    Node *current = table->buckets[index];
    Node *prev = NULL;
    
    while (current != NULL) {
        if (current->key == key) {
            // Remove node from chain
            if (prev == NULL) {
                // Deleting first node in chain
                table->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            
            printf("Deleted: Key %d (from index %d)\n", key, index);
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    
    printf("Key %d not found for deletion!\n", key);
    return false;
}

/*
 * Display the entire hash table structure
 */
void hash_display(HashTable *table) {
    if (!table) return;
    
    printf("\n=== Hash Table Contents ===\n");
    for (int i = 0; i < table->size; i++) {
        printf("Bucket[%d]: ", i);
        
        Node *current = table->buckets[i];
        if (current == NULL) {
            printf("Empty\n");
        } else {
            while (current != NULL) {
                printf("(Key:%d, Val:%d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("===========================\n\n");
}

/*
 * Free all memory allocated for hash table
 */
void hash_destroy(HashTable *table) {
    if (!table) return;
    
    for (int i = 0; i < table->size; i++) {
        Node *current = table->buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(table->buckets);
    free(table);
    printf("Hash table destroyed and memory freed.\n");
}

/*
 * Main function demonstrating hash table operations
 */
int main(void) {
    printf("=== Hash Table Implementation Demo ===\n\n");
    
    // Create hash table
    HashTable *table = create_hash_table(TABLE_SIZE);
    if (!table) {
        fprintf(stderr, "Failed to create hash table!\n");
        return 1;
    }
    
    // Test data
    int keys[] = {15, 25, 35, 45, 5, 16, 26, 36};
    int values[] = {100, 200, 300, 400, 500, 600, 700, 800};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    // Insert operations
    printf("--- Insert Operations ---\n");
    for (int i = 0; i < n; i++) {
        hash_insert(table, keys[i], values[i]);
    }
    
    // Display hash table
    hash_display(table);
    
    // Search operations
    printf("--- Search Operations ---\n");
    hash_search(table, 25);   // Should find
    hash_search(table, 100);  // Should not find
    hash_search(table, 5);    // Should find
    printf("\n");
    
    // Update operation (insert existing key)
    printf("--- Update Operation ---\n");
    hash_insert(table, 25, 999);  // Update value
    hash_display(table);
    
    // Delete operations
    printf("--- Delete Operations ---\n");
    hash_delete(table, 35);   // Should delete
    hash_delete(table, 100);  // Should not find
    hash_display(table);
    
    // Test collision handling
    printf("--- Testing Collision Handling ---\n");
    printf("Keys 15, 25, 35, 45 all hash to same bucket (index 5)\n");
    printf("They are stored in a linked list chain.\n\n");
    
    // Statistics
    printf("--- Hash Table Statistics ---\n");
    printf("Table Size: %d buckets\n", TABLE_SIZE);
    printf("Total Items: %d\n", n - 1);  // One deleted
    printf("Load Factor: %.2f\n", (float)(n - 1) / TABLE_SIZE);
    printf("\n");
    
    // Clean up
    hash_destroy(table);
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}
