/*
Program Name: Trie Data Structure Implementation in C
Author: Dimpesh Panwar
Description:
    This program implements a simple Trie (prefix tree) data structure in C.
    It supports insertion and searching of lowercase English words.

Problem Statement:
    Implement a Trie data structure to efficiently store and search strings.

Example:
    Input:
        Insert: "hello", "hey", "good", "go"
        Search: "hey" → Found
        Search: "goku" → Not Found

Output:
    Words inserted successfully!
    Search results as shown above.

Time Complexity:
    Insert: O(L) per word
    Search: O(L) per word
    where L = length of the word.

Usage:
    Compile: gcc trie.c -o trie
    Run: ./trie
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Structure representing a node in the Trie
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Function to create a new Trie node
TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Function to insert a word into the Trie
void insert(TrieNode *root, const char *word) {
    TrieNode *crawler = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (crawler->children[index] == NULL)
            crawler->children[index] = createNode();
        crawler = crawler->children[index];
    }
    crawler->isEndOfWord = true;
}

// Function to search for a word in the Trie
bool search(TrieNode *root, const char *word) {
    TrieNode *crawler = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (crawler->children[index] == NULL)
            return false;
        crawler = crawler->children[index];
    }
    return crawler->isEndOfWord;
}

// Function to free Trie memory
void freeTrie(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        freeTrie(root->children[i]);
    free(root);
}

// Driver code
int main() {
    TrieNode *root = createNode();

    // Insert words into the Trie
    insert(root, "hello");
    insert(root, "hey");
    insert(root, "good");
    insert(root, "go");

    printf("Words inserted successfully!\n");

    // Search for words
    printf("Searching 'hey': %s\n", search(root, "hey") ? "Found" : "Not Found");
    printf("Searching 'goku': %s\n", search(root, "goku") ? "Found" : "Not Found");

    // Free memory
    freeTrie(root);

    return 0;
}
