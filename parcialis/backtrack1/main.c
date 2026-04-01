#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    int n, k;

    FILE *fin = fopen("bemenet.txt", "r");
    if (fin == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl!\n");
        return 1;
    }

    if (fscanf(fin, "%d %d", &n, &k) != 2) {
        printf("Hiba: Hibas fajl formatum!\n");
        fclose(fin);
        return 1;
    }

    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &numbers[i]);
    }

    fclose(fin);

    int *sol = (int *)malloc(k * sizeof(int));
    bool found = false;

    solve_safe(0, 0, n, k, numbers, sol, &found);

    if (!found) {
        printf("Nincs megoldas\n");
    }

    free(numbers);
    free(sol);

    return 0;
}