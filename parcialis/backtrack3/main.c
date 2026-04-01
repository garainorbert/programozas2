#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    int n, k, d;

    FILE *fin = fopen("bemenet.txt", "r");
    if (fin == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl!\n");
        return 1;
    }

    if (fscanf(fin, "%d %d %d", &n, &k, &d) != 3) {
        printf("Hiba: Hibas fajl formatum!\n");
        fclose(fin);
        return 1;
    }

    int *items = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &items[i]);
    }
    fclose(fin);

    int *sol = (int *)malloc(k * sizeof(int));
    bool *used = (bool *)calloc(n, sizeof(bool));
    bool found = false;

    solve_museum(0, n, k, d, items, sol, used, &found);

    if (!found) {
        printf("Nincs megoldas\n");
    }

    free(items);
    free(sol);
    free(used);

    return 0;
}