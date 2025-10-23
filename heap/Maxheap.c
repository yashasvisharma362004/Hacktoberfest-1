#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* Implement a Max Heap with functions to insert, extract max, and print the heap array.*/
typedef struct {
    int *array;
    int size;
    int capacity;
} Heap;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

Heap* createHeap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int *)malloc(capacity * sizeof(int));
    return heap;
}

void heapify(Heap *heap, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

void insertHeap(Heap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }
    int i = heap->size++;
    heap->array[i] = value;
    
    while (i != 0 && heap->array[(i-1)/2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax(Heap *heap) {
    if (heap->size <= 0) return INT_MIN;
    if (heap->size == 1) return heap->array[--heap->size];
    
    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify(heap, 0);
    return root;
}

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->array[i]);
    printf("\n");
}

int main() {
    Heap *heap = createHeap(10);
    insertHeap(heap, 3);
    insertHeap(heap, 2);
    insertHeap(heap, 15);
    insertHeap(heap, 5);
    insertHeap(heap, 4);
    insertHeap(heap, 45);
    
    printf("Max Heap array: ");
    printHeap(heap);
    
    printf("Extracted max: %d\n", extractMax(heap));
    printf("Heap after extraction: ");
    printHeap(heap);
    
    free(heap->array);
    free(heap);
    return 0;
}
