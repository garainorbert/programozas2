#include <stdio.h>
#include "functions.h"

int main() {
    FILE *file = fopen("bemenet.txt", "r");
    if (file == NULL) {
        printf("Hiba: A bemenet.txt nem talalhato!\n");
        return 1;
    }

    if (fscanf(file, "%d %d", &n, &S) != 2) {
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &halmaz[i]);
    }

    fclose(file);

    backtrack(0, 0, 0);

    if (talalt == 0) {
        printf("Nincs megoldas\n");
    }

    return 0;
}