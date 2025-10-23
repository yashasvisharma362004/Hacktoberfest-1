#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* Given K sorted arrays, merge them into one sorted array efficiently using a min heap.

Explanation:

1.Insert the first element of each array into a min heap.

2.Extract the minimum element and insert the next element from the extracted element's array.

3.Continue until all elements are merged.*/

typedef struct {
    int value;      
    int arrIndex;   
    int eleIndex;   
} HeapNode;


typedef struct {
    HeapNode *harr; 
    int size;
} MinHeap;

void swap(HeapNode *x, HeapNode *y) {
    HeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < heap->size && heap->harr[left].value < heap->harr[smallest].value)
        smallest = left;
    if (right < heap->size && heap->harr[right].value < heap->harr[smallest].value)
        smallest = right;
    if (smallest != i) {
        swap(&heap->harr[i], &heap->harr[smallest]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(MinHeap *heap) {
    int i = (heap->size - 1)/2;
    for (; i >= 0; i--)
        minHeapify(heap, i);
}

void mergeKArrays(int arrays[][5], int k, int n) {
    int total = k * n;
    int *output = (int *) malloc(total * sizeof(int));
    int outputIndex = 0;

    MinHeap heap;
    heap.size = k;
    heap.harr = (HeapNode *) malloc(k * sizeof(HeapNode));

    
    for (int i = 0; i < k; i++) {
        heap.harr[i].value = arrays[i][0];
        heap.harr[i].arrIndex = i;
        heap.harr[i].eleIndex = 1; 
    }

    buildMinHeap(&heap);

    
    while (outputIndex < total) {
        HeapNode root = heap.harr[0];
        output[outputIndex++] = root.value;

        if (root.eleIndex < n) {
            
            heap.harr[0].value = arrays[root.arrIndex][root.eleIndex];
            heap.harr[0].arrIndex = root.arrIndex;
            heap.harr[0].eleIndex = root.eleIndex + 1;
        } else {
        
            heap.harr[0].value = INT_MAX;
        }

        minHeapify(&heap, 0);
    }

    // Print merged array
    printf("Merged array: ");
    for (int i = 0; i < total; i++)
        printf("%d ", output[i]);
    printf("\n");

    free(output);
    free(heap.harr);
}

int main() {
    
    int arrays[3][5] = {
        {1, 3, 5, 7, 9},
        {0, 2, 6, 8, 10},
        {4, 11, 13, 15, 17}
    };

    mergeKArrays(arrays, 3, 5);
    
    return 0;
}
