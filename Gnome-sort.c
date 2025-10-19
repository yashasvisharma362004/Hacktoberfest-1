#include <stdio.h>

void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        
        if (arr[index] >= arr[index - 1])
            index++;  // in correct order, move forward
        else {
            // swap elements
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;

            index--; // move backward after swap
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    gnomeSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
