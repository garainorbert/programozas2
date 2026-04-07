//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>

//Abszolút különbség
int get_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

bool igeretes_museum(int step, int *sol, bool *used, int *items, int d) {
    if (used[sol[step]]) return false;

    if (step > 0) {
        if (get_diff(items[sol[step - 1]], items[sol[step]]) < d) {
            return false;
        }
    }

    return true;
}

void solve_museum(int step, int n, int k, int d, int *items, int *sol, bool *used, bool *found) {
    for (int i = 0; i < n; i++) {
        sol[step] = i;

        if (igeretes_museum(step, sol, used, items, d)) {

            used[i] = true;

            if (step == k - 1) {
                *found = true;
                for (int j = 0; j <= step; j++) {
                    printf("%d ", items[sol[j]]);
                }
                printf("\n");
            } else {
                solve_museum(step + 1, n, k, d, items, sol, used, found);
            }

            used[i] = false;
        }
    }
}