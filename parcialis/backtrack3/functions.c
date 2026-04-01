//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>

//Abszolút különbség
int get_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void solve_museum(int step, int n, int k, int d, int *items, int *sol, bool *used, bool *found) {
    if (step == k) {
        *found = true;
        for (int i = 0; i < k; i++) {
            printf("%d ", items[sol[i]]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (step > 0) {
                if (get_diff(items[sol[step - 1]], items[i]) < d) {
                    continue;
                }
            }

            used[i] = true;
            sol[step] = i;

            solve_museum(step + 1, n, k, d, items, sol, used, found);

            used[i] = false;
        }
    }
}