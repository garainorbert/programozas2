//
// Created by norbe on 2026. 04. 27..
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int compare_movies(const void *a, const void *b) {
    Movie *m1 = (Movie *)a;
    Movie *m2 = (Movie *)b;

    if (m1->end < m2->end) return -1;
    if (m1->end > m2->end) return 1;
    return 0;
}

void solve_filmfesztival(int n, Movie movies[]) {
    qsort(movies, n, sizeof(Movie), compare_movies);

    printf("A kivalasztott filmek:\n");

    int count = 1;
    int last_end_time = movies[0].end;

    printf("- Film #%d: %d:00 - %d:00\n", movies[0].id, movies[0].start, movies[0].end);

    for (int i = 1; i < n; i++) {
        if (movies[i].start >= last_end_time) {
            printf("- Film #%d: %d:00 - %d:00\n", movies[i].id, movies[i].start, movies[i].end);
            last_end_time = movies[i].end;
            count++;
        }
    }

    printf("Osszesen %d filmet tudsz megnezni.\n", count);
}
