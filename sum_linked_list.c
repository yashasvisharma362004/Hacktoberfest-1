/*
Program Name: Sum of Two Numbers Represented as Linked Lists

Problem Statement:
Given two numbers represented as linked lists, where each node contains a single digit
and digits are stored in reverse order, return the sum as a linked list.

Example:
Input:  l1 = 2->4->3, l2 = 5->6->4
Output: 7->0->8   (because 342 + 465 = 807)

Concepts Used:
- Linked List
- Carry management during addition

Author: Your Name
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add two numbers represented as linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = createNode(0);
    Node* current = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->data; l1 = l1->next; }
        if (l2) { sum += l2->data; l2 = l2->next; }

        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    Node* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    Node* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    Node* result = addTwoNumbers(l1, l2);
    printf("Sum: ");
    printList(result);

    return 0;
}
