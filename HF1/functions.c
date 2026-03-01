//
// Created by norbe on 2026. 03. 01..
//

#include "functions.h"

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol)
{
    if (currentRow == rows)
        return;

    if (currentCol == cols)
    {
        readMatrixRecursive(matrix, rows, cols, currentRow + 1, 0);
        return;
    }

    scanf("%d", &matrix[currentRow][currentCol]);

    readMatrixRecursive(matrix, rows, cols, currentRow, currentCol + 1);
}

void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol)
{
    if (currentRow == rows)
        return;

    if (currentCol == cols)
    {
        printf("\n");
        printMatrixRecursive(matrix, rows, cols, currentRow + 1, 0);
        return;
    }

    printf("%d ", matrix[currentRow][currentCol]);

    printMatrixRecursive(matrix, rows, cols, currentRow, currentCol + 1);
}

int isThreeDigitMirror(int x)
{
    if (x < 100 || x > 999)
        return 0;

    int first = x / 100;
    int last = x % 10;

    return first == last;
}

void printThreeDigitMirrorsByRowRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol)
{
    if (currentRow == rows)
        return;

    if (currentCol == 0)
        printf("Sor %d: ", currentRow);

    if (currentCol == cols)
    {
        printf("\n");
        printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, currentRow + 1, 0);
        return;
    }

    if (isThreeDigitMirror(matrix[currentRow][currentCol]))
        printf("%d ", matrix[currentRow][currentCol]);

    printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, currentRow, currentCol + 1);
}