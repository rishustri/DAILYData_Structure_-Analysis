#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;

    // Step 1: Allocate array of row pointers
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) return 1; // Check for allocation failure

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) return 1;
    }

    // Example usage: Assign and print a value
    matrix[1][2] = 42;
    printf("Value at [1][2]: %d\n", matrix[1][2]);

    // --- DEALLOCATION ---
    // Step 1: Free each individual row
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    // Step 2: Free the array of row pointers
    free(matrix);
    matrix = NULL; // Avoid dangling pointer

    return 0;
}
