#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    FILE *f = fopen("bemenet.txt", "r");
    if (f == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl a mappaban!\n");
        return 1;
    }

    int capacity, n;

    if (fscanf(f, "%d %d", &capacity, &n) != 2) {
        printf("Hibas bemeneti formatum a fajlban!\n");
        fclose(f);
        return 1;
    }

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        fclose(f);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%d %d", &items[i].weight, &items[i].value);
        items[i].id = i + 1;
    }

    fclose(f);

    solve_hatizsak(capacity, n, items);

    free(items);

    return 0;
}