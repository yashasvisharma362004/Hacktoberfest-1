#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* Find Median of a Stream of Integers Using Two Heaps */
typedef struct {
    int *array;
    int size;
    int capacity;
} Heap;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

Heap* createHeap(int capacity) {
    Heap *heap = (Heap*) malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*) malloc(capacity * sizeof(int));
    return heap;
}

void maxHeapify(Heap *heap, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

void minHeapify(Heap *heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;
    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMaxHeap(Heap *heap, int val) {
    if (heap->size == heap->capacity) return;
    int i = heap->size++;
    heap->array[i] = val;
    while(i != 0 && heap->array[(i-1)/2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}


void insertMinHeap(Heap *heap, int val) {
    if (heap->size == heap->capacity) return;
    int i = heap->size++;
    heap->array[i] = val;
    while(i != 0 && heap->array[(i-1)/2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}


int extractMax(Heap *heap) {
    if (heap->size <= 0) return INT_MIN;
    if (heap->size == 1) return heap->array[--heap->size];
    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    maxHeapify(heap, 0);
    return root;
}

int extractMin(Heap *heap) {
    if (heap->size <= 0) return INT_MAX;
    if (heap->size == 1) return heap->array[--heap->size];
    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    minHeapify(heap, 0);
    return root;
}


void getMedian(int stream[], int n) {
    Heap *maxHeap = createHeap(n); 
    Heap *minHeap = createHeap(n); 

    for (int i = 0; i < n; i++) {
        int num = stream[i];

        if (maxHeap->size == 0 || num <= maxHeap->array[0]) {
            insertMaxHeap(maxHeap, num);
        } else {
            insertMinHeap(minHeap, num);
        }

        
        if (maxHeap->size > minHeap->size + 1) {
            int val = extractMax(maxHeap);
            insertMinHeap(minHeap, val);
        } else if (minHeap->size > maxHeap->size + 1) {
            int val = extractMin(minHeap);
            insertMaxHeap(maxHeap, val);
        }

        
        if (maxHeap->size == minHeap->size) {
            double median = (maxHeap->array[0] + minHeap->array[0]) / 2.0;
            printf("Median after inserting %d: %.1f\n", num, median);
        } else if (maxHeap->size > minHeap->size) {
            printf("Median after inserting %d: %d\n", num, maxHeap->array[0]);
        } else {
            printf("Median after inserting %d: %d\n", num, minHeap->array[0]);
        }
    }

    free(maxHeap->array);
    free(minHeap->array);
    free(maxHeap);
    free(minHeap);
}

int main() {
    int stream[] = {5, 15, 1, 3, 8, 7, 9, 10, 6, 11};
    int n = sizeof(stream)/sizeof(stream[0]);
    getMedian(stream, n);
    return 0;
}
