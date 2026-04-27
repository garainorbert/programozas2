#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    FILE *f = fopen("bemenet.txt", "r");
    if (f == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl a mappaban!\n");
        return 1;
    }

    double capacity;
    int n;

    if (fscanf(f, "%lf %d", &capacity, &n) != 2) {
        printf("Hibas bemeneti formatum a fajlban!\n");
        fclose(f);
        return 1;
    }

    Candy *candies = (Candy *)malloc(n * sizeof(Candy));
    if (candies == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        fclose(f);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%lf %lf", &candies[i].weight, &candies[i].price);
        candies[i].id = i + 1;
        candies[i].ratio = candies[i].price / candies[i].weight;
    }

    fclose(f);

    solve_edesseges(capacity, n, candies);

    free(candies);

    return 0;
}