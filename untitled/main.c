#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    // Fájl megnyitása olvasásra
    FILE *file = fopen("bemenet.txt", "r");

    if (file == NULL) {
        printf("Hiba: A bemenet.txt nem talalhato!\n");
        return 1;
    }

    // Beolvasás a fájlból (scanf helyett fscanf)
    if (fscanf(file, "%d %d", &n, &m) != 2) {
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &terkep[i][j]);
            visited[i][j] = 0;
        }
    }

    // Fájl bezárása, miután beolvastunk mindent
    fclose(file);

    // Ha a start és a cél ugyanaz
    if (n == 1 && m == 1) {
        printf("1\n");
        return 0;
    }

    // DFS indítása
    backtrack(0, 0, 1);

    if (max_hossz == -1) {
        printf("nincs megoldas\n");
    } else {
        printf("%d\n", max_hossz);
    }

    return 0;
}