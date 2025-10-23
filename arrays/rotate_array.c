/*
Program: Rotate Array (Left Rotation)
Problem Statement: 
    Rotate an array of integers to the left by 'd' positions.

Example: 
    Input: arr=[2, 3, 5, 6, 7], d=2
    Output: [5, 6, 7, 2, 3]

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<stdio.h>

//reverse part of the array
void reverse(int arr[], int start, int end){
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

//rotate array to left by d positions
void rotateArray(int arr[], int n, int d){
    d=d%n;//Handle d>n
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

int main(){
    int n, d;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate: ");
    scanf("%d", &d);

    rotateArray(arr, n, d);

    printf("Array after left rotation: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}