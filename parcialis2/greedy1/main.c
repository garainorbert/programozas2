#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    FILE *f = fopen("bemenet.txt", "r");
    if (f == NULL) {
        printf("Hiba: Nem talalhato a bemenet.txt fajl a mappaban!\n");
        return 1;
    }

    int n;

    if (fscanf(f, "%d", &n) != 1) {
        printf("Hibas bemeneti formatum a fajlban!\n");
        fclose(f);
        return 1;
    }

    Movie *movies = (Movie *)malloc(n * sizeof(Movie));
    if (movies == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        fclose(f);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%d %d", &movies[i].start, &movies[i].end);
        movies[i].id = i + 1;
    }

    fclose(f);

    solve_filmfesztival(n, movies);

    free(movies);

    return 0;
}