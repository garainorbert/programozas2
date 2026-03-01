#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int rows, cols;

    printf("Sorok szama: ");
    scanf("%d", &rows);

    printf("Oszlopok szama: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Matrix elemei:\n");
    readMatrixRecursive(matrix, rows, cols, 0, 0);

    printf("\nMatrix:\n");
    printMatrixRecursive(matrix, rows, cols, 0, 0);

    printf("\nHaromszamjegyu tukorszamok soronkent:\n");
    printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, 0, 0);

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
