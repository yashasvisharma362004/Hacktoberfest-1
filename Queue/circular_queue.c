#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", element);
        return;
    }

    if (front == -1) // first element
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    printf("Inserted %d\n", element);
}

// Function to delete an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) { // only one element was present
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, element;

    while (1) {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
