#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    FILE *f = fopen("bemenet.txt", "r");
    if (f == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl a mappaban!\n");
        return 1;
    }

    int rows, cols;

    if (fscanf(f, "%d %d", &rows, &cols) != 2) {
        printf("Hibas bemeneti formatum a fajlban!\n");
        fclose(f);
        return 1;
    }

    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(f, "%d", &grid[i][j]);
        }
    }

    fclose(f);

    solve_almakert(rows, cols, grid);

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}