#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    int n, k, w;

    FILE *fin = fopen("bemenet.txt", "r");
    if (fin == NULL) {
        printf("Hiba: A bemenet.txt nem talalhato!\n");
        return 1;
    }

    if (fscanf(fin, "%d %d %d", &n, &k, &w) != 3) {
        printf("Hiba: Rossz fajlformatum!\n");
        fclose(fin);
        return 1;
    }

    int *weights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &weights[i]);
    }
    fclose(fin);

    int *sol = (int *)malloc(k * sizeof(int));
    bool *used = (bool *)calloc(n, sizeof(bool));
    bool found = false;

    solve_delivery(0, 0, n, k, w, weights, sol, used, &found);

    if (!found) {
        printf("Nincs megoldas\n");
    }

    free(weights);
    free(sol);
    free(used);

    return 0;
}