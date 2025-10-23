#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Implement a priority queue using a min heap data structure. The priority queue should support the following operations:

1.Insert a new element

2.Extract the minimum element

3.Display the current elements in the heap */

typedef struct {
    int *array;
    int size;
    int capacity;
} MinHeap;


void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}


MinHeap* createHeap(int capacity) {
    MinHeap *heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*) malloc(capacity * sizeof(int));
    return heap;
}


void minHeapify(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;
    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}


void insert(MinHeap *heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    
    int i = heap->size++;
    heap->array[i] = key;

    
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


int extractMin(MinHeap *heap) {
    if (heap->size <= 0)
        return INT_MAX;
    if (heap->size == 1)
        return heap->array[--heap->size];

    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    minHeapify(heap, 0);
    return root;
}


void displayHeap(MinHeap *heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->array[i]);
    printf("\n");
}

int main() {
    MinHeap *heap = createHeap(10);

    
    insert(heap, 10);
    insert(heap, 4);
    insert(heap, 15);
    insert(heap, 20);
    insert(heap, 0);
    insert(heap, 8);

    displayHeap(heap);
    printf("Extracted min: %d\n", extractMin(heap));
    displayHeap(heap);

    free(heap->array);
    free(heap);
    return 0;
}
