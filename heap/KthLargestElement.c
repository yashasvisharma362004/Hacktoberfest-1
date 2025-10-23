#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*  Find the Kth Largest Element in an Array Using a Heap */
void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}


void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(int heap[], int size) {
    for (int i = (size - 1)/2; i >= 0; i--)
        minHeapify(heap, size, i);
}

int kthLargest(int arr[], int n, int k) {
    int *heap = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
        heap[i] = arr[i];
    buildMinHeap(heap, k);

    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            minHeapify(heap, k, 0);
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 0, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printf("Kth largest element is %d\n", kthLargest(arr, n, k));
    return 0;
}
