/*
Program: Lucky Number in a Matrix
Author: M. Sri Silpa
Description: A lucky number is the element that is the minimum in its row and maximum in its column.
*/

#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Lucky numbers in the matrix are:\n");
    for (int i = 0; i < m; i++) {
        int min_row = a[i][0];
        int col_index = 0;
        for (int j = 1; j < n; j++) {
            if (a[i][j] < min_row) {
                min_row = a[i][j];
                col_index = j;
            }
        }

        int is_lucky = 1;
        for (int k = 0; k < m; k++) {
            if (a[k][col_index] > min_row) {
                is_lucky = 0;
                break;
            }
        }

        if (is_lucky)
            printf("%d\n", min_row);
    }

    return 0;
}
