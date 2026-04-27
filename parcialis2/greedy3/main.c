#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    FILE *f = fopen("bemenet.txt", "r");
    if (f == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl a mappaban!\n");
        return 1;
    }

    int amount;

    if (fscanf(f, "%d", &amount) != 1) {
        printf("Hibas bemeneti formatum a fajlban!\n");
        fclose(f);
        return 1;
    }

    fclose(f);

    solve_penztaros(amount);

    return 0;
}