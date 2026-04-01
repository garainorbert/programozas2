#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    int n, m;

    FILE *fin = fopen("bemenet.txt", "r");
    if (fin == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl!\n");
        return 1;
    }

    if (fscanf(fin, "%d %d", &n, &m) != 2) {
        printf("Hiba: Hibas fajl formatum!\n");
        fclose(fin);
        return 1;
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    bool **visited = (bool **)malloc(n * sizeof(bool *));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        visited[i] = (bool *)calloc(m, sizeof(bool));
        for (int j = 0; j < m; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }

    fclose(fin);

    int *path_x = (int *)malloc(n * m * sizeof(int));
    int *path_y = (int *)malloc(n * m * sizeof(int));

    visited[0][0] = true;

    if (!solve_ghost(0, 0, n, m, matrix, visited, path_x, path_y, 0)) {
        printf("Nincs megoldas\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(visited[i]);
    }
    free(matrix);
    free(visited);
    free(path_x);
    free(path_y);

    return 0;
}