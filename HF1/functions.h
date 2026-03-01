//
// Created by norbe on 2026. 03. 01..
//

#ifndef HF1_FUNCTIONS_H
#define HF1_FUNCTIONS_H

#include <stdio.h>

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
int isThreeDigitMirror(int x);
void printThreeDigitMirrorsByRowRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);


#endif //HF1_FUNCTIONS_H
